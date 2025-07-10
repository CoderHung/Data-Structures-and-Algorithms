import time

def fake_download(file_id):
    time.sleep(2)
    return f"Data from file {file_id}"
