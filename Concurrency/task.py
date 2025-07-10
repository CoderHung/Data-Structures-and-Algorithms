import time

def fake_download(file_id):
    time.sleep(1)
    return f"Data from file {file_id}"
