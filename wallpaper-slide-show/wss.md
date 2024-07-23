# Wallpaper Slide Show

![wss](https://github.com/user-attachments/assets/4e69709f-f90c-4cf6-9f31-b70489199c9b)

This program allows you to change your desktop wallpaper by cycling through images from a specified folder.
You can control the delay between wallpaper changes and choose whether to repeat the process indefinitely.

### How to use:
Download or copy the code <a href="">`wss.cpp`</a>.<br>
Compile the program:
```console
g++ wss.cpp -o wss
```
Execute the compiled program with the following arguments:
```console
wss <image_folder_path> <delay_ms> <repeat_count>
```
- `<image_folder_path>`: Path to the folder containing your images.
- `<delay_ms>`: Delay time in milliseconds between wallpaper changes.
- `<repeat_count>`: Number of times to repeat the wallpaper rotation (use a negative number for infinite repetition).
#### Examples:
This will change the wallpaper every 10000 milliseconds (10 second) and repeat the process twice.
```console
wss C:\Path\to\images\folder\ 10000 2
```
To repeat indefinitely, use a negative value for <repeat_count>.
```console
wss C:\Path\to\images\folder\ 10000 -1
```
**Notes:**
- Ensure that the specified image folder contains compatible image files (e.g., JPEG, PNG).
- Administrative privileges might be required for wallpaper changes.
- Performance might be different depending on the system hardware.

