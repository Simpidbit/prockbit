import os

shield_files = ["Makefile", "CMakeFiles", "cmake_install.cmake", "upload.py"]
origin = "prockbit"

if __name__ == "__main__":
    dir_files = os.listdir()
    upload_files = []

    for filename in dir_files:
        if filename not in shield_files:
            upload_files.append(filename)

    upload_files_str = ""
    for each in upload_files:
        upload_files_str += each + " "

    os.system(f"git add {upload_files_str}")
    commit_msg = input("Commit: ")
    os.system(f"git commit {commit_msg}")
    os.system(f"git push {origin}")
