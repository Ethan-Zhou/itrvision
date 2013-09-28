/*
 * FormatPGM.cpp
 *
 *  Created on: 2013-9-27
 *      Author: ghdawn
 */

#include "itrbase.h"
#include "formatpgm.h"
#include <sstream>
using std::stringstream;

namespace itr_vision
{
    FormatPGM::FormatPGM()
    {

    }

    FormatPGM::~FormatPGM()
    {
    }

    IFormat::ConvertResult FormatPGM::GetInfo(U8* Data, S32 Length, ImageInfo& ImgInfo)
    {
        U8 head1, head2;
        S32 width, height;
        stringstream str;
        str << Data;
        str >> head1 >> head2;
        str >> width >> height;
        if ((head1 != 'P') || (head2 != '5'))
            return IFormat::FormatIllegal;

        S32 bit = 9;
        bit += (width > 1000) ? 4 : ((width > 100) ? 3 : (width > 10 ? 2 : 1));
        bit += (height > 1000) ? 4 : ((height > 100) ? 3 : (height > 10 ? 2 : 1));
        if (Length != (width * height + bit))
            return IFormat::LengthIllegal;
        ImgInfo.Width = width;
        ImgInfo.Height = height;
        ImgInfo.ColorChannel = 3;
        ImgInfo.PixelSize = 3;
        return IFormat::Success;
    }

    IFormat::ConvertResult FormatPGM::ToImage(U8* Data, S32 Length, ImageGray& Img)
    {
        U8 head1, head2;
        S32 width, height;
        S32 bit;
        stringstream str;
        str << Data;
        str >> head1 >> head2;
        str >> width >> height;
        str >> bit;

        bit = 9;
        bit += (width > 1000) ? 4 : ((width > 100) ? 3 : (width > 10 ? 2 : 1));
        bit += (height > 1000) ? 4 : ((height > 100) ? 3 : (height > 10 ? 2 : 1));
        if ((head1 != 'P') || (head2 != '5'))
            return IFormat::FormatIllegal;
        if (Length != (width * height + bit))
            return IFormat::LengthIllegal;
        U8 data;
        S16* img = Img.GetPixels();
        for (int j = 0; j < height; ++j)
        {
            for (int i = 0; i < width; ++i)
            {
                str >> data;
                (*img) = data;
                ++img;
            }
        }
        return IFormat::Success;
    }
    IFormat::ConvertResult FormatPGM::ToImage(U8* Data, S32 Length, ImageARGB& Img)
    {
        U8 head1, head2;
        S32 width, height;
        S32 bit;
        stringstream str;
        str << Data;
        str >> head1 >> head2;
        str >> width >> height;
        str >> bit;

        if ((head1 != 'P') || (head2 != '5'))
            return IFormat::FormatIllegal;

        bit = 9;
        bit += (width > 1000) ? 4 : ((width > 100) ? 3 : (width > 10 ? 2 : 1));
        bit += (height > 1000) ? 4 : ((height > 100) ? 3 : (height > 10 ? 2 : 1));
        if (Length != (width * height + bit))
            return IFormat::LengthIllegal;
        U8 data;
        U32* img = Img.GetPixels();
        for (int j = 0; j < height; ++j)
        {
            for (int i = 0; i < width; ++i)
            {
                str >> data;
                (*img) = (data) | (data << 8) | (data << 16);
                ++img;
            }
        }
        return IFormat::Success;
    }
    IFormat::ConvertResult FormatPGM::ToBinary(ImageARGB& Img, U8* Data, S32& Length)
    {

        if (Length < (Img.GetWidth() * Img.GetHeight() * 3 + 15))
            return IFormat::LengthIllegal;
        stringstream str;
        str << "P6" << '\n';
        str << Img.GetWidth() << ' ' << Img.GetHeight() << '\n';
        str << 255 << '\n';
        U32* data = Img.GetPixels();
        S32 temp;
        U8 r, g, b;
        while (str.get(r))
        {
            *Data = r;
            ++Data;
        }
        for (int i = 0; i < Img.GetPixelsNumber(); ++i)
        {
            r = (*data) >> 16;
            g = ((*data) & 0xFF00) >> 8;
            b = (*data) & 0xFF;
            itr_math::NumericalObj->Floor(0.299 * r + 0.587 * g + 0.114 * b, temp);
            *Data = (U8) temp;
            ++Data;
        }

        return IFormat::Success;
    }
    IFormat::ConvertResult FormatPGM::ToBinary(ImageGray& Img, U8* Data, S32& Length)
    {

        if (Length < (Img.GetWidth() * Img.GetHeight() * 3 + 15))
            return IFormat::LengthIllegal;
        stringstream str;
        str << "P6" << '\n';
        str << Img.GetWidth() << ' ' << Img.GetHeight() << '\n';
        str << 255 << '\n';
        S16* data = Img.GetPixels();
        U8 p;
        while (str.get(p))
        {
            *Data = p;
            ++Data;
        }
        for (int i = 0; i < Img.GetPixelsNumber(); ++i)
        {
            p = *data;
            *Data=p;
            ++data;
            ++Data;
        }
        return IFormat::Success;
    }
} // namespace itr_vision