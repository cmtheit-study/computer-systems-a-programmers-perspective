import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
from pathlib import Path

"""
一种编程语言
"""
class Lang:
    name = 'lang'
    color = 'black'
    def __init__(self):
        self.lines = 0

    def test_add_lines(self, f: str | Path):
        if self.is_lang(f):
            self.add_lines(f)
            return True
        else:
            return False

    def add_lines(self, f: str | Path):
        with open(f, "r") as f:
            self.lines += len(f.readlines())

    def is_lang(self, f: str | Path):
        return True

class CLang(Lang):
    name = 'C'
    color = '#555555'
    def is_lang(self, f: str | Path):
        f = Path(f).resolve()
        return f.name.endswith(".c") or f.name.endswith(".h")

class PyLang(Lang):
    name = 'Python'
    color = '#3572A5'
    def is_lang(self, f: str | Path):
        f = Path(f)
        return f.name.endswith(".py")

class MakefileLang(Lang):
    name = 'Makefile'
    color = '#427819'
    def is_lang(self, f: str | Path):
        f = Path(f)
        return f.name == "Makefile" or f.name.endswith(".make")

class ShellLang(Lang):
    name = 'Shell'
    color = '#89E051'
    def is_lang(self, f: str | Path):
        f = Path(f)
        return f.name.endswith(".sh")

class AssemblyLang(Lang):
    name = 'Assembly'
    color = '#6E4C13'
    def is_lang(self, f: str | Path):
        f = Path(f)
        return f.name.endswith(".s")

"""
语言池，可以绘制语言分布
"""
class LangPool:
    def __init__(self, langs: list[Lang], files: list[str | Path]):
        self.langs = langs
        for f in files:
            f = Path(f).resolve()
            for lang in langs:
                if lang.test_add_lines(f):
                    break
        self.fig, (self.pie_ax, self.bar_ax) = plt.subplots(2, 1)

    @property
    def sizes(self):
        return tuple(lang.lines for lang in self.langs)

    @property
    def labels(self):
        return tuple(lang.name for lang in self.langs)

    @property
    def colors(self):
        return tuple(lang.color for lang in self.langs)

    def show(self):
        self.pie_ax.pie(x=self.sizes, labels=self.labels, colors=self.colors, autopct='%1.1f%%')
        self.pie_ax.set_title("Programming Languages Distribution")
        self.pie_ax.axis("equal")
        bars = self.bar_ax.bar(self.labels, self.sizes, color=self.colors)
        for bar in bars:
            height = bar.get_height()
            self.bar_ax.text(bar.get_x() + bar.get_width() / 2, height, str(height), ha='center', va='bottom')
        plt.show()
