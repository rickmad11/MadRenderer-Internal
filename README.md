# MadRenderer Internal

Simple Rendering Library, only supports Directx11

## How to Use

1. **Compile for Release and Debug Mode**  
   Simply compile for **Release** and **Debug** mode. Choose either **x86** or **x64** depending on your target architecture.

2. **Copy MadRenderer Internal Library**  
   Copy the `MadRenderer Internal.lib` file and place it in your project's **lib** directory.

3. **DirectXTK lib**  
   You will then need to copy the **DirectXTK** lib file. You can find it here:
   DirectXTK-oct2024/Bin/Desktop_2022_Win10/x64/Release/DirectXTK.lib

5. **Copy DirectXTK Headers**  
Ensure you also copy the **DirectXTK** headers from the following directory into your project:
DirectXTK-oct2024/Inc

**Alternative**  
Alternatively, you can add the **DirectXTK-oct2024** project as a reference to your solution. This will allow you to link against the DirectXTK project directly, instead of manually copying files.

You can find a example here: https://github.com/rickmad11/Titanfall-2-Internal 

https://github.com/rickmad11/Titanfall-2-Internal/tree/master/Mad%20Framework/lib/MadRenderer%20Internal
