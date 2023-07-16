import os
import subprocess
import matplotlib.pyplot as plt
from pathlib import Path
import sys
from FileLister import *
from Lang import *

class LineCounter:
    def __init__(self, file_lister: FileLister, langs: list[Lang]):
        self.files = file_lister.files()
        self.lang_pool = LangPool(langs, self.files)

    def show(self):
        self.lang_pool.show()

if __name__ == '__main__':
    line_counter = LineCounter(GitFileLister(path='./'), [CLang(), PyLang(), ShellLang(), AssemblyLang(), MakefileLang()])
    line_counter.show()


