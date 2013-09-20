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

#include "math_test.h"
#include "itrbase.h"

void TestCalculate()
{
    //Objects
    itr_math::Numerical numericalObj;
    itr_math::Calculate calculateObj(&numericalObj);
    itr_math::Statistics statisticsObj(&numericalObj,&calculateObj);

    //Data
    S32 SourceS32A[50];
    S32 SourceS32B[50];
    S32 ResultS32[50];
    F32 SourceF32A[50];
    F32 SourceF32B[50];
    F32 ResultF32A[50];
    F32 ResultF32;
    S32 Length = 50;
    S32 AddAns = 2450;
    F32 AddAnsF = 245.0;
    //Init
    for (S32 i = 0; i < Length; i++)
    {
        SourceS32A[i] = i;
        SourceS32B[i] = i;
        SourceF32A[i] = i;
        SourceF32A[i] = i;
    }
    //Add
    calculateObj.Add(SourceF32A,SourceF32B,Length,ResultF32A);
    calculateObj.Sum(ResultF32A,Length,ResultF32);
    assert(ResultF32==2450);
    //Sub...

    TRACE_INFO("OK TestCalculate()");
}

void TestNumerical()
{

}

void TestStatistics()
{

}
