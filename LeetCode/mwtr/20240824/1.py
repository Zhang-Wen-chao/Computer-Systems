def determine_resolution(h, w):
    # Determine the lower value between h and w
    min_dimension = min(h, w)
    
    if min_dimension < 360:
        return "break"
    elif min_dimension >= 360 and min_dimension < 480:
        return "360P"
    elif min_dimension >= 480 and min_dimension < 720:
        return "480P"
    elif min_dimension >= 720 and min_dimension < 1080:
        return "720P"
    elif min_dimension >= 1080 and min_dimension < 2160:
        return "1080P"
    elif min_dimension >= 2160:
        return "4K"
    
def process_input():
    T = int(input())
    for _ in range(T):
        h, w = map(int, input().split())
        print(determine_resolution(h, w))

# Example of using the process_input function
if __name__ == "__main__":
    process_input()
