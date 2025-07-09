import pdb

def divide(a, b):
    pdb.set_trace()  # Pauses here
    result = a / b
    pdb.set_trace()  # Pauses here
    return result

divide(10, 2)
