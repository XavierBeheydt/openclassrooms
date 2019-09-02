from os import path

def launch_analysis(data_file):
    directory = path.dirname(path.dirname(__file__))
    path_to_file = path.join(directory, "data", data_file)

    try:
        with open(path_to_file, "r") as f:
            preview = f.readline()
    except FileNotFoundError:
        print("File is not founded.")
    except:
        print("Destination unknown")
    else:
        print("Preview is : {}".format(preview))

if __name__ == "__main__":
    launch_analysis('current_mps.csv')