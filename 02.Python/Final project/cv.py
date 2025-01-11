import cv2
import mediapipe as mp

# Initialize Mediapipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_drawing = mp.solutions.drawing_utils

# Initialize webcam
cap = cv2.VideoCapture(0)

def detect_finger_movements(hand_landmarks):
    finger_chars = ["A", "B", "C", "D", "E"]
    finger_states = []

    # Thumb
    if hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP].x < hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_IP].x:
        finger_states.append(1)
    else:
        finger_states.append(0)

    # Fingers
    for id in range(1, 5):
        if hand_landmarks.landmark[mp_hands.HandLandmark(id * 4)].y < hand_landmarks.landmark[mp_hands.HandLandmark(id * 4 - 2)].y:
            finger_states.append(1)

        else:
            finger_states.append(0)

    closed_fingers = [finger_chars[i] for i, state in enumerate(finger_states) if state == 0]
    if closed_fingers:
        print("Closed fingers:", closed_fingers)

while cap.isOpened():
    success, image = cap.read()
    if not success:
        break

    # Flip the image horizontally for a later selfie-view display
    image = cv2.flip(image, 1)
    image_rgb = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

    # Process the image and find hands
    results = hands.process(image_rgb)

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            mp_drawing.draw_landmarks(image, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            detect_finger_movements(hand_landmarks)

    cv2.imshow('Hand Tracking', image)
    if cv2.waitKey(5) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
