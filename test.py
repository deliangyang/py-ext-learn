import testa

print(testa.sub(1, 2))
print(testa.add(1, 2))

print(testa.print("aaaaaaa"))


class Test:
    """this is the class doc."""
    def __init__(self):
        print("aaaxxxxxx")

t = Test()
print(testa.test_object(t))
