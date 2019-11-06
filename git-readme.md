# How to push to our repository

1. Clone our repository
```console
git clone https://github.com/UnsignedGitGit/TubesAlstrukdatSTI.git
```

2. Open the folder 'TubesAlstrukdatSTI' and change the directory to said folder
```console
chdir TubesAlstrukdatSTI
```
for windows

```console
cd TubesAlstrukdatSTI
```
for linux

3. Make new branch on your local repository
```console
git checkout -b "newbranch"
```

4. Then, you can add all files in the folder to HEAD index
```console
git add .
```

5. Commit your changes on the local repository, you should include commit message using -m flag
```console
git config --global user.name "YourUserName"
git config --global user.email "youremail@email.com"
git commit -m "commit message"
```

6. then, push to origin remote repository
```console
git push --set-upstream origin "newbranch"
```