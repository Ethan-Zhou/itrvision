/*
 *
 *   Copyright (C) 2013 BUAA iTR Research Center. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * matrix.cc
 *  Created on: 2013-9-14
 *      Author: zhouyi
 */

#include <stddef.h>
#include "../platform/platform.h"
#include "math.h"

namespace itr_math
{
    Numerical* Matrix::numericalObj = NULL;
    Calculate* Matrix::calculateObj = NULL;

    /*
     * 初始化一个指定行列数的空矩阵(自动分配内存)
     */
    Matrix::Matrix(S32 Row, S32 Col)
    {
        assert(numericalObj!=NULL && calculateObj!=NULL);
        assert(Row>0 && Col>0);
        data = new F32[Row * Col];
        assert(data!=NULL);
        row = Row;
        col = Col;
        localData = true;
    }
    /*
     * 初始化一个指定行列数的矩阵(以传入的指针为数据区)
     */
    Matrix::Matrix(S32 Row, S32 Col, F32* Data)
    {
        assert(numericalObj!=NULL && calculateObj!=NULL);
        assert(Row>0 && Col>0);
        data = Data;
        assert(data != NULL);
        row = Row;
        col = Col;
        localData = false;
    }
    /*
     * 初始化一个指定阶数的方阵(自动分配内存)
     */
    Matrix::Matrix(S32 RowCol)
    {
        assert(numericalObj!=NULL && calculateObj!=NULL);
        assert(RowCol>0);
        data = new F32[RowCol * RowCol];
        assert(data!=NULL);
        row = RowCol;
        col = RowCol;
        localData = true;
    }
    /*
     * 初始化完全一样的矩阵(Clone)
     */
    Matrix::Matrix(const Matrix& Mat)
    {
        assert(numericalObj!=NULL && calculateObj!=NULL);
        data = new F32[Mat.GetRow() * Mat.GetCol()];
        assert(data!=NULL);
        row = Mat.GetRow();
        col = Mat.GetCol();
        localData = true;
    }
    /*
     * 回收自动分配的内存
     */
    Matrix::~Matrix()
    {
        if (localData == true)
        {
            delete data;
        }
    }
    //**********初等变换**********
    /*
     * 将RowNoAdd行加至RowNoResult行
     */
    void Matrix::AddRow(S32 RowNoAdd, S32 RowNoResult)
    {
        assert(RowNoAdd <= row && RowNoResult <= row);
        calculateObj->Add(data + (RowNoAdd - 1) * col, data + (RowNoResult - 1) * col, col,
                data + (RowNoResult - 1) * col);
    }
    /*
     * 将Data加至RowNoResult行
     */
    void Matrix::AddRow(F32* Data, S32 RowNoResult)
    {
        assert(Data!=NULL);
        assert(RowNoResult <= row);
        calculateObj->Add(Data, data + (RowNoResult - 1) * col, col,
                data + (RowNoResult - 1) * col);
    }
    /*
     * 将RowNoSub行减至RowNoResult行
     */
    void Matrix::SubRow(S32 RowNoSub, S32 RowNoResult)
    {
        assert(RowNoSub <= row && RowNoResult <= row);
        calculateObj->Sub(data + (RowNoResult - 1) * col, data + (RowNoSub - 1) * col, col,
                data + (RowNoResult - 1) * col);
    }
    /*
     * 将Data减至RowNoResult行
     */
    void Matrix::SubRow(F32* Data, S32 RowNoResult)
    {
        assert(Data!=NULL);
        assert(RowNoResult <= row);
        calculateObj->Sub(data + (RowNoResult - 1) * col, Data, col,
                data + (RowNoResult - 1) * col);
    }
    /*
     * 将RowNoResult行乘以K
     */
    void Matrix::MulRow(F32 K, S32 RowNoResult)
    {
        assert(RowNoResult <= row);
        calculateObj->Multi(K, data + (RowNoResult - 1) * col, col, data + (RowNoResult - 1) * col);
    }
    //Swap Row
    /*
     * 交换RowNoA行和RowNoB行
     */
    void Matrix::SwapRow(S32 RowNoA, S32 RowNoB)
    {
        assert(RowNoA <= row);
        assert(RowNoB <= row);
        MemorySwap(data + (RowNoA - 1) * col, data + (RowNoB - 1) * col, col);
    }
    /*
     * 将ColNoAdd列加至ColNoResult列
     */
    void Matrix::AddCol(S32 ColNoAdd, S32 ColNoResult)
    {
        assert(ColNoAdd<=col);
        assert(ColNoResult<=col);
        for (S32 i = 0; i < row; i++)
            data[i * col + ColNoResult] = data[i * col + ColNoAdd] + data[i * col + ColNoResult];
    }
    /*
     * 将Data加至ColNoResult列
     */
    void Matrix::AddCol(F32* Data, S32 ColNoResult)
    {
        assert(Data!=NULL);
        assert(ColNoResult<=col);
        for (S32 i = 0; i < row; i++)
            data[i * col + ColNoResult] = Data[i] + data[i * col + ColNoResult];
    }
    /*
     * 将ColNoSub列减至ColNoResult列
     */
    void Matrix::SubCol(S32 ColNoSub, S32 ColNoResult)
    {
        assert(ColNoSub<col);
        assert(ColNoResult<col);
        for (S32 i = 0; i < row; i++)
            data[i * col + ColNoResult] = data[i * col + ColNoResult] - data[i * col + ColNoSub];
    }
    /*
     * 将Data减至ColNoResult列
     */
    void Matrix::SubCol(F32* Data, S32 ColNoResult)
    {
        assert(Data!=NULL);
        assert(ColNoResult<=col);
        for (S32 i = 0; i < row; i++)
            data[i * col + ColNoResult] = data[i * col + ColNoResult] - Data[i];
    }
    /*
     * 将ColNoResult列乘以K
     */
    void Matrix::MulCol(F32 K, S32 ColNoResult)
    {
        assert(ColNoResult < col);
        for (S32 i = 0; i < row; i++)
            data[i * col + ColNoResult] = data[i * col + ColNoResult] * K;
    }
    /*
     * 交换ColNoA列和ColNoB列
     */
    void Matrix::SwapCol(S32 ColNoA, S32 ColNoB)
    {
        assert(ColNoA<=col);
        assert(ColNoB<=col);
        F32 temp;
        for (S32 i = 0; i < row; i++)
        {
            temp = data[i * col + ColNoB];
            data[i * col + ColNoB] = data[i * col + ColNoA];
            data[i * col + ColNoA] = temp;
        }
    }
    //**********常量相关计算**********
    /*
     * 全部元素加上K
     */
    void Matrix::Add(F32 K)
    {
        for (S32 i = 0; i < col; i++)
        {
            calculateObj->Add(K, data + i * col, col, data + i * col);
        }
    }
    /*
     * 全部元素乘以K
     */
    void Matrix::Mul(F32 K)
    {
        for (S32 i = 0; i < col; i++)
        {
            calculateObj->Multi(K, data + i * col, col, data + i * col);
        }
    }
    //**********向量相关计算**********
    /*
     * 左乘行向量
     */
    void Matrix::LeftMulRow(const Vector& Vec, Matrix& MatResult) const
    {
        assert(Vec.GetDim()==MatResult.row);
        for(S32 i =0;i<col;i++)
            calc
    }
}
// namespace itr_math
