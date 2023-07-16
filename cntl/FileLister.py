import os
from pathlib import Path
import shutil
import subprocess

class FileLister:
    def __init__(self, *, path: str | Path):
        self.path = Path(path)

    def files(self):
        return []

"""
列出所有 git 文件，不论是否是 git 仓库
"""
class GitFileLister(FileLister):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if not self.path.exists():
            raise f"目录 {self.path} 不存在！"
        if not self.path.is_dir():
            raise f"{self.root_dir} 不是目录！"
        crd = Path(os.getcwd());

        os.chdir(self.path)
        is_gitrepo = subprocess.run(['git', 'status'], capture_output=True).returncode == 0
        if not is_gitrepo:
            subprocess.run(['git', 'init'], capture_output=True)
        self.__files = [Path(file).resolve() for file in subprocess.run(['git', 'ls-files', '--recurse-submodules'], capture_output=True).stdout.decode('utf-8').split('\n')]
        if not is_gitrepo:
            shutil.rmtree('.git')

        os.chdir(crd)

    def files(self):
        return self.__files

__all__ = ('FileLister', 'GitFileLister')