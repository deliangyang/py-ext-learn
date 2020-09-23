from distutils.core import setup, Extension

def main():
    setup(name="test",
          version="1.0.0",
          description="Python interface for the test C library function",
          author="ydl",
          author_email="yang623601391@gmail.com",
          ext_modules=[Extension("testa", ["library.c"])])

if __name__ == "__main__":
    main()