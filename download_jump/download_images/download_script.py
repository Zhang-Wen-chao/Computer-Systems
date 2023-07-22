import subprocess
import os
import glob
import argparse

def main():
    # Create the argument parser
    parser = argparse.ArgumentParser(description='Download script')
    parser.add_argument('--start', type=int, help='Start number')
    parser.add_argument('--end', type=int, help='End number')
    args = parser.parse_args()

    # Retrieve the values of start and end from the command-line arguments
    start = args.start if args.start is not None else 0
    end = args.end if args.end is not None else 20

    # Define number range
    numbers = list(range(start, end))
    # Define main folder name
    main_folder_name = f"{start}-{end-1}"

    subprocess.run(["python", "get_urls.py"] + list(map(str, numbers)))

    with open("config.h", "w") as f:
        f.write(f'#define MAIN_FOLDER_NAME "{main_folder_name}"\n')

    subprocess.run(["g++", "-o", "download_images", "download_images.cpp", "-lcurl"])

    # Create the output and error file names based on main_folder_name
    output_file = f"{main_folder_name}.out"
    error_file = f"{main_folder_name}.err"

    # Redirect the output to the output file
    with open(output_file, "w") as f_out:
        # Redirect the error to the error file
        with open(error_file, "w") as f_err:
            subprocess.run(["./download_images", main_folder_name], check=True, stdout=f_out, stderr=f_err)

    # Remove the config file
    os.remove("config.h")
    # Remove *urls.txt file
    # for file in glob.glob('*urls.txt'):
    #     os.remove(file)
    # Remove the download_images file
    os.remove("download_images")

if __name__ == "__main__":
    main()