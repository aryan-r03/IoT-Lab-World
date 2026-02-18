import cv2
import numpy as np

def floyd_steinberg(image):
    img = image.astype(np.float32)
    h, w = img.shape

    for y in range(h):
        for x in range(w):
            old = img[y, x]
            new = 255.0 if old > 127 else 0.0
            img[y, x] = new
            err = old - new

            if x + 1 < w:
                img[y, x + 1]     += err * 7 / 16
            if y + 1 < h:
                if x - 1 >= 0:
                    img[y + 1, x - 1] += err * 3 / 16
                img[y + 1, x]         += err * 5 / 16
                if x + 1 < w:
                    img[y + 1, x + 1] += err * 1 / 16

    return np.clip(img, 0, 255).astype(np.uint8)


def convert_video(input_file, output_file, fps=10):
    video = cv2.VideoCapture(input_file)
    total = 0

    with open(output_file, "wb") as out:
        while True:
            ret, frame = video.read()
            if not ret:
                break

            gray = cv2.resize(frame, (128, 64))
            gray = cv2.cvtColor(gray, cv2.COLOR_BGR2GRAY)

            # Floyd-Steinberg dithering instead of binary threshold
            bw = floyd_steinberg(gray)

            # 8 pixels per byte
            packed = []
            for row in bw:
                for col in range(0, 128, 8):
                    byte = 0
                    for bit in range(8):
                        if row[col + bit] > 0:
                            byte |= (1 << bit)
                    packed.append(byte)

            out.write(bytes(packed))
            total += 1

    print(f"Done! {total} frames → {total} KB saved to {output_file}")


convert_video("video.mp4", "video.bin")
