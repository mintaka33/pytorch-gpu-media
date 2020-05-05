import numpy as np
import cv2 as cv
import argparse

cap = cv.VideoCapture('test.264', cv.CAP_INTEL_MFX)

ret, frame = cap.read()
frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

cv.imwrite('out.bmp', frame_gray)

print('done')
