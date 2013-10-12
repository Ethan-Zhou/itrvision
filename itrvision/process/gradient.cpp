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
 * gradient.cpp
 *  Created on: 2013-10-9
 *      Author: ghdawn
 */

#include "gradient.h"

namespace itr_vision
{

} // namespace itr_vision

void itr_vision::Gradient::Gradientx(const ImageGray& img, ImageGray& dx)
{
    assert(img.MatchWidthHeight(dx));
    for(int y=0;y<img.GetHeight();++y)
        for(int x=0;x<img.GetWidth();++x)
        {
            if(x==0||y==0||x==img.GetWidth()-1||y==img.GetHeight()-1)
                dx(y,x)=img(y,x);
            else
            {
                dx(y,x)=(img(y,x+1)-img(y,x-1))>>1;
            }
        }
}

void itr_vision::Gradient::Gradienty(const ImageGray& img, ImageGray& dy)
{
    assert(img.MatchWidthHeight(dy));
        for(int y=0;y<img.GetHeight();++y)
            for(int x=0;x<img.GetWidth();++x)
            {
                if(x==0||y==0||x==img.GetWidth()-1||y==img.GetHeight()-1)
                    dy(y,x)=img(y,x);
                else
                {
                    dy(y,x)=(img(y+1,x)-img(y-1,x))>>1;
                }
            }
}