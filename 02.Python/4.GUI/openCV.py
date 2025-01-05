import cv2

def main():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("error opening webcam")
        exit()
    while True:
        ret,frame = cap.read()
        if not ret:
            print("can't receive frame")
            break
        cv2.imshow('frame',frame)
        key = cv2.waitKey(1)
        if key == ord('q'):
            break
        if key == ord('c'):
            cv2.imwrite('test.jpg',frame)
    
    cap.release()
    cv2.destroyAllWindows()
main()