#! /usr/bin/env python3

import sys
import datetime
import fitz

from PIL import Image, ImageEnhance

t = datetime.datetime.now()


def px_image(path):
    img = Image.open(path)

    en1 = ImageEnhance.Contrast(img)  # 对比度
    out = en1.enhance(10)

    en2 = ImageEnhance.Sharpness(out)  # 锐化
    end = en2.enhance(10)
    end.save(path, "png")


def pdf_image(
    pdfPath,
):
    pdf = fitz.open(pdfPath)

    for pg in range(0, pdf.pageCount):
        page = pdf[pg]

        trans = fitz.Matrix(2, 2)
        pm = page.get_pixmap(matrix=trans)

        ph = t.strftime("%m-%d %H:%M") + " " + str(pg) + ".png"
        pm.save(ph)

        px_image(ph)

    pdf.close()


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("指定 PDF 文件的路径!")
    else:
        pdf_image(sys.argv[1])
        print("完成")
