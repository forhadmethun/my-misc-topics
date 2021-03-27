Git is distributed revision control and source code management system 
### VCS
 - A software that helps software developers to work together and maintain a complete history
 - functions of vcs
   - work simultaniously
   - doens't allow overriding code
   - maintains history
 - types of vcs
   - distributed
   - centralized
     -  uses a central server to store all files and enables team collaboration but prone to single point of failure of the central server, or disk corruption of cenral server
### Distrubted Version Control System
 - not only we can check latest snapshot of directory but also fully  mirror the repository 
 - if server goes down then repo can be copied back from any client
 - many offline operations like commit, create branches, view logs and perform other operation
 - network is only necessary to publish the changes and take the latest changes
### Advantages of Git
    - free and open source
    - fast and small
    - implicit backup
    - security
      - uses SHA1 so impossible to change file, date, commit message and any other
    - no need of powerful hardware
    - easier branching
### DVCS Terminologies
    - local repository
      - VCS tool provides a private workplace as a working copy. Developers make changes in their private workplace and after commit, these changes become a part of the repository
    - Working Directory and Staging Area or Index
      - The working directory is the place where files are checked out
      - Git doesn’t track each and every modified file. Whenever you do commit an operation, Git looks for the files present in the staging area. Only those files present in the staging area are considered for commit and not all the modified files.    
      - workflow 
        - working directory ---(git add)--> staging area ----(git commit) --> git repository
    - Blobs
      - each version of file represented by blob which doesn't contain any metadata about the file
    - Trees
      - an object represent a directory
      - a tree is a binary file that stores references to blobs
    - Commits
      - hold current state of a repository
      - it is also named by SHA1
      - it's a node of linked list where parent is previous commit if any commit has multiple parent it means it has created by merging two branches
    - Branches
      - git has master branch, new branches are created to work on new feature once completed merged with master and we can delete that branch, every branch is referenced by HEAD and on evry commit this HEAD is updated
    - Tags
      - tag assigns meaningful name with specific version of repo, similiar to branch but tag's are immutable 
      - developers create tags for product release
    - Clone
      - create instance of repository
      - developer can perform many operation with this local repository but only network get involved while sync.
    - Pull
      - copies the changes from a remote instance to local one
    - Push
      - copies changes from local repository instance to remote one
      - used to store the changes permanently
    - HEAD
      - HEAD is a pointer, which always points to the latest commit in the branch
      - stored in .git/refs/heads/ directory.
    - Revision
      - represents the version of source code
      - revisions are represented by commits
      - commits are identified by SHA1
    - URL
      - represents the location of the git repository 
### Environment Setup
#### Version Check
```
git --version
```
#### Customize Git Environment
- Git stores all global configurations in .gitconfig file, which is located in your home directory. 
- To set these configuration values as global, add the --global option, and if you omit --global option, then your configurations are specific for the current Git repository.
```
 git config --global user.name "Forhad Hossain"
 git config --global user.email "forhadmethun@gmail.com"
 git config --list
```
### Git Life Cycle
General work-flow - 
 - clone git repo as working copy
 - modify working copy by adding/editing
 - if necessary take change from others
 - review change before commit
 - commit change, if everything fine then push the changes to the repository
 - after commiting if there is any issue then correct the last commit and push the changes to the repository


### Git Commands
```
pwd
mkdir repo
cd repo
git init
echo 'write something to readme' > readme
git status -s
git add .
git status -s
git commit -m 'initial commit'
git log
git remote add origin 'git_repo_url'
git push origin master

```


# Git Caching username and password
```
git config --global credential.helper store

```
# Git Basics
```
# https://github.com/forhadmethun/coursera-fewd-with-react
git config --global user.name <username>
git config --global user.mail

git log --oneline

git status

git commit -m 'message'
git checkout <commit-identifier> <file> #the file will be automatically staged, so to unstage need to execute following command
git reset HEAD <file>
git checkout -- <file> #to take to the previous commit
git reset <file>

git remote add origin <repo-url>
git push -u origin master


git clone <repo-url>

#.gitignore 

```

# Git Merge vs Git Rebase
## Result of `git merge master`
```
*   63c6403  (master) Merge "second_branch" in "master"
|\
| |
* | 33facc8 Commit 3
| |
| * 3b36f32  (second_branch) Detached commit
| |
|/
* 29af11f  Commit 2
|
* 1439f8e  Commit 1
```

## Result of `git rebase master`
```
* a018520  (HEAD -> second_branch) Detached commit
|
* 33facc8  (master) Commit 3
|
* 29af11f  Commit 2
|
* 1439f8e  Commit 1
```

## Replace existing remote origin
```
git remote set-url origin https://github.com/forhadmethun/watchflix.git

```