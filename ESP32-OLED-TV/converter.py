import cv2

def convert_video(input_file, output_file, fps=10):
    video = cv2.VideoCapture(input_file)
    total = 0

    with open(output_file, "wb") as out:
        while True:
            ret, frame = video.read()
            if not ret:
                break

            gray = cv2.resize(frame, (128, 64))                         # display size
            gray = cv2.cvtColor(gray, cv2.COLOR_BGR2GRAY)               # Colour = Monochromatic
            _, bw = cv2.threshold(gray, 128, 255, cv2.THRESH_BINARY)

            # 8 pixels per byte
            packed = []
            for row in bw:
                for col in range(0, 128, 8): # 0 - 128 , 8-bit package
                    byte = 0
                    for bit in range(8):
                        if row[col + bit] > 0:
                            byte |= (1 << bit)
                    packed.append(byte)

            out.write(bytes(packed))
            total += 1

    print(f"Done! {total} frames → {total} KB saved to {output_file}")


convert_video("video.mp4", "video.bin")
