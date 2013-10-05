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
 * math_test.cc
 *  Created on: 2013年9月17日
 *      Author: ZYC
 */

#include "mathtest.h"
#include "calculatetest.h"
#include "itrbase.h"
#include "math.h"
#include "stdio.h"

void TestMathInit()
{
    itr_math::MathObjStandInit();
}

void TestMathdeDeinit()
{
    itr_math::MathObjStandDeinit();
}

void TestCalculate()
{
    //Init
    itr_math::MathObjStandInit();
    //Test Data
    S16 A_S16[] =
    { 2, 2 };
    S16 B_S16[] =
    { 1, 1 };
    S16 C_S16[] =
    { 0, 0 };

    S32 A_S32[] =
    { 2, 2 };
    S32 B_S32[] =
    { 1, 1 };
    S32 C_S32[] =
    { 0, 0 };

    F32 A_F32[] =
    { 2, 2 };
    F32 B_F32[] =
    { 1, 1 };
    F32 C_F32[] =
    { 0, 0 };

    F32 CalResultF32;
    S32 CalResultS32;
    S16 CalResutlS16;

    //AddTest
    itr_math::CalculateObj->Add(A_S16, B_S16, 2, C_S16);
    assert(C_S16[0] == A_S16[0] + B_S16[0] && C_S16[1] == A_S16[1] + B_S16[1]);
    itr_math::CalculateObj->Add(A_S32, B_S32, 2, C_S32);
    assert(C_S32[0] == A_S32[0] + B_S32[0] && C_S32[1] == A_S32[1] + B_S32[1]);
    itr_math::CalculateObj->Add(A_F32, B_F32, 2, C_F32);
    assert(C_F32[0] == A_F32[0] + B_F32[0] && C_F32[1] == A_F32[1] + B_S32[1]);
    //SubTest
    itr_math::CalculateObj->Sub(A_S16, B_S16, 2, C_S16);
    assert(C_S16[0] == A_S16[0] - B_S16[0] && C_S16[1] == A_S16[1] - B_S16[1]);
    itr_math::CalculateObj->Sub(A_S32, B_S32, 2, C_S32);
    assert(C_S32[0] == A_S32[0] - B_S32[0] && C_S32[1] == A_S32[1] - B_S32[1]);
    itr_math::CalculateObj->Sub(A_F32, B_F32, 2, C_F32);
    assert(C_F32[0] == A_F32[0] - B_F32[0] && C_F32[1] == A_F32[1] - B_S32[1]);
    //MultiTest
    itr_math::CalculateObj->Multi(A_S16, B_S16, 2, C_S16);
    assert(C_S16[0] == A_S16[0] * B_S16[0] && C_S16[1] == A_S16[1] * B_S16[1]);
    itr_math::CalculateObj->Multi(A_S32, B_S32, 2, C_S32);
    assert(C_S32[0] == A_S32[0] * B_S32[0] && C_S32[1] == A_S32[1] * B_S32[1]);
    itr_math::CalculateObj->Multi(A_F32, B_F32, 2, C_F32);
    assert(C_F32[0] == A_F32[0] * B_F32[0] && C_F32[1] == A_F32[1] * B_S32[1]);
    //DivTest
    itr_math::CalculateObj->Div(A_S16, B_S16, 2, C_S16);
    assert(C_S16[0] == A_S16[0] / B_S16[0] && C_S16[1] == A_S16[1] / B_S16[1]);
    itr_math::CalculateObj->Div(A_S32, B_S32, 2, C_S32);
    assert(C_S32[0] == A_S32[0] / B_S32[0] && C_S32[1] == A_S32[1] / B_S32[1]);
    itr_math::CalculateObj->Div(A_F32, B_F32, 2, C_F32);
    assert(C_F32[0] == A_F32[0] / B_F32[0] && C_F32[1] == A_F32[1] / B_S32[1]);
    //DivOrderTest
    itr_math::CalculateObj->DivOrder(A_S16, 1, 2, C_S16);
    assert(C_S16[0] == A_S16[0] / 2 && C_S16[1] == A_S16[1] / 2);
    itr_math::CalculateObj->DivOrder(A_S32, 1, 2, C_S32);
    assert(C_S32[0] == A_S32[0] / 2 && C_S32[1] == A_S32[1] / 2);
    //OffsetTest
    itr_math::CalculateObj->Offset(A_S16, 2, 2, C_S16);
    assert(C_S16[0] == A_S16[0] + 2 && C_S16[1] == A_S16[1] + 2);
    itr_math::CalculateObj->Offset(A_S32, 2, 2, C_S32);
    assert(C_S32[0] == A_S32[0] + 2 && C_S32[1] == A_S32[1] + 2);
    itr_math::CalculateObj->Offset(A_F32, 2, 2, C_F32);
    assert(C_F32[0] == A_F32[0] + 2 && C_F32[1] == A_F32[1] + 2);
    //ScaleTest
    itr_math::CalculateObj->Scale(A_S16, 2, 2, C_S16);
    assert(C_S16[0] == A_S16[0] * 2 && C_S16[1] == A_S16[1] * 2);
    itr_math::CalculateObj->Scale(A_S32, 2, 2, C_S32);
    assert(C_S32[0] == A_S32[0] * 2 && C_S32[1] == A_S32[1] * 2);
    itr_math::CalculateObj->Scale(A_F32, 2, 2, C_F32);
    assert(C_F32[0] == A_F32[0] * 2 && C_F32[1] == A_F32[1] * 2);
    //NormalizationTest
    itr_math::CalculateObj->Normalization(A_F32, 2, C_F32);
    assert(C_F32[0]*C_F32[0] + C_F32[1]*C_F32[1] -1 < 0.0001);
    //AbsTest
    itr_math::CalculateObj->Abs(A_S16, 2, C_S16);
    assert(fabs(A_S16[0])==C_S16[0] && fabs(A_S16[1])==C_S16[1]);
    itr_math::CalculateObj->Abs(A_S32, 2, C_S32);
    assert(fabs(A_S32[0])==C_S32[0] && fabs(A_S32[1])==C_S32[1]);
    itr_math::CalculateObj->Abs(A_F32, 2, C_F32);
    assert(fabs(A_F32[0])==C_F32[0] && fabs(A_F32[1])==C_F32[1]);
    //OppositeTest
    itr_math::CalculateObj->Opposite(A_S16, 2, C_S16);
    assert(A_S16[0] * (-1) == C_S16[0] && A_S16[1] * (-1) == C_S16[1]);
    itr_math::CalculateObj->Opposite(A_S32, 2, C_S32);
    assert(A_S32[0] * (-1) == C_S32[0] && A_S32[1] * (-1) == C_S32[1]);
    itr_math::CalculateObj->Opposite(A_F32, 2, C_F32);
    assert(A_F32[0] * (-1) == C_F32[0] && A_F32[1] * (-1) == C_F32[1]);
    //AddSumTest
    itr_math::CalculateObj->AddSum(A_S16, 2, CalResutlS16);
    assert(CalResutlS16 == A_S16[0] + A_S16[1]);
    itr_math::CalculateObj->AddSum(A_S32, 2, CalResultS32);
    assert(CalResultS32 == A_S32[0] + A_S32[1]);
    itr_math::CalculateObj->AddSum(A_F32, 2, CalResultF32);
    assert(CalResutlS16 == A_S16[0] + A_S16[1]);
    //MultiSum
    itr_math::CalculateObj->MultiSum(A_S16, B_S16, 2, CalResutlS16);
    assert(CalResutlS16 == A_S16[0]*B_S16[0] + A_S16[1]*B_S16[1]);
    itr_math::CalculateObj->MultiSum(A_S16, B_F32, 2, CalResutlS16);
    assert(CalResutlS16 == A_S16[0] *B_F32[0] + A_S16[1]*B_F32[1]);
    itr_math::CalculateObj->MultiSum(A_S32, B_S32, 2, CalResultS32);
    assert(CalResultS32 == A_S32[0]*B_S32[0] + A_S32[1] * B_S32[1]);
    itr_math::CalculateObj->MultiSum(A_F32, B_F32, 2, CalResultF32);
    //ProductTest
    itr_math::CalculateObj->Product(A_S16, 2, CalResutlS16);
    assert(CalResutlS16 = A_S16[0]*A_S16[1]);
    itr_math::CalculateObj->Product(A_S32, 2, CalResultS32);
    assert(CalResultS32 == A_S32[0]*A_S32[1]);
    itr_math::CalculateObj->Product(A_F32, 2, CalResultF32);
    assert(CalResultF32 == A_F32[0]*A_F32[1]);
    //SetTest
    itr_math::CalculateObj->Set(C_S16, 2, 2);
    assert(C_S16[0] == 2 && C_S16[1] == 2);
    itr_math::CalculateObj->Set(C_S32, 2, 2);
    assert(C_S32[0] == 2 && C_S32[1] == 2);
    itr_math::CalculateObj->Set(C_F32, 2, 2);
    assert(C_F32[0] == 2 && C_F32[1] == 2);
    TRACE_INFO("OK TestCalculate()");
}

void TestNumerical()
{

}

void TestStatistics()
{
    S32 SourceS32[50];
    F32 SourceF32[50];
    S32 ResultS32;
    F32 ResultF32;
    S32 Length = 50;
    for (S32 i = 0; i < Length; i++)
    {
        SourceS32[i] = i;
        SourceF32[i] = i;
    }
    itr_math::StatisticsObj->Max(SourceS32, Length, ResultS32);
    assert(ResultS32 == 49);
    itr_math::StatisticsObj->Min(SourceS32, Length, ResultS32);
    assert(ResultS32 == 0);
    itr_math::StatisticsObj->Mean(SourceS32, Length, ResultS32);
    assert(ResultS32 == 24);
    itr_math::StatisticsObj->RMS(SourceS32, Length, ResultS32);
    assert(ResultS32 == 28);
    itr_math::StatisticsObj->STD(SourceS32, Length, ResultS32);
    assert(ResultS32 == 14);
}

void TestVector()
{
//itr_math::Vector v(3);
//F32 vector(2, 0x1111, 1);
//CopyFrom
}

void TestMatrix()
{
    //Init
    itr_math::MathObjStandInit();
    //测试数据
    /* 1   4  9
     * 16 25 36
     * 49 64 91
     */
    F32 data1[3 * 3];
    F32 data2[3 * 3];
    F32 data3[3 * 3] = {0,0,0,0,0,0,0,0,0};
    F32 ExData[] = {1,1,1};
    for (S32 i = 0; i < 3 * 3; i++)
    {
        data1[i] = (i + 1) * (i + 1);
        data2[i] = (i + 1) * (i + 1);
    }
    F32* Data1 = data1;
    F32* Data2 = data2;
    F32* Data3 = data3;

    itr_math::Matrix Source1(3, 3, Data1);
    itr_math::Matrix Source2(3, 3, Data2);
    itr_math::Matrix Result(3, 3, Data3);
    //初等变换
    Source1.AddRow(1, 2);
    assert(Source1.GetData()[3] == 17 && Source1.GetData()[4] == 29 && Source1.GetData()[5] == 45);
    Source1.SubRow(1,2);
    assert(Source1.GetData()[3] == 16 && Source1.GetData()[4] == 25 && Source1.GetData()[5] == 36);
    Source1.AddRow(ExData,1);
    assert(Source1.GetData()[0] == 2 && Source1.GetData()[1] == 5 && Source1.GetData()[2] == 10);
    Source1.SubRow(ExData,1);
    assert(Source1.GetData()[0] == 1 && Source1.GetData()[1] == 4 && Source1.GetData()[2] == 9);
    Source1.AddCol(1,2);
    assert(Source1.GetData()[1] == 5 && Source1.GetData()[4] == 41 && Source1.GetData()[7] == 113);

    TRACE_INFO("OK TestMatrix()");
}
void TestCalculateTest()
{
    F32 A[] =
    { 1, 1 };
    F32 B[] =
    { 2, 2 };
    F32 C[] =
    { 0, 0 };

    CalculateTest calcObjT;
    itr_math::Calculate* calcObj = &calcObjT;
    calcObj->Add(A, B, 2, C);

//    itr_math::Calculate calcObj=CalculateTest();
//    calcObj.Add(A,B,2,C);
}
