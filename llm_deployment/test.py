import modal

stub = modal.Stub("example-get-started")


@stub.function()
def square(x):
    print("This code is running on a remote worker!")
    return x**2


@stub.function()
def sum(x, y):
    """
    This is a local function.
    """
    return x + y


@stub.local_entrypoint()
def main():
    print("the square is", square.remote(42))
    return 0

if __name__ == "__main__":
    main()
