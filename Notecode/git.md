https://blog.csdn.net/a18307096730/article/details/124586216?spm=1001.2014.3001.5502

`git init` 初始化当前目录为git仓库

`ll` 查看当前文件夹目录

`touch [file name]`添加文件到当前文件夹

`git status`查看文件状态

`git add .`添加所有文件到暂存区

`git commit -m "[describe]"`将文件从暂存区添加到本地仓库

`git-log`查看提交日志

`git reset --hard [commitID]`版本切换/回退

`git reflog`查看已删除的提交日志

`touch .gitignore`创建忽略列表

`vi .gitignore`编辑

`*.[file suffix]`忽略所有该后缀的文件

`git branch`查看分支

`git branch [branch name]`创建分支

`git checkout [branch name]`切换分支

`git chekout -b [branch name]`切换并创建分支

`git merge [branch name]`合并分支（一般合并到master）

`git branch -d [branch name]`删除分支（-D强制删除） 