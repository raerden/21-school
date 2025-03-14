cd ai_help
git checkout -b key-branch
cp main.key main-2.key
git add main-2.key
git checkout -b feature/3-key
cp main.key main-3.key
git add main-3.key
git commit -m'feature/3-key copy main-3.key from main.key'
git checkout key-branch
git push origin key-branch
git checkout feature/3-key
git push origin feature/3-key
git merge feature/3-key
git commit -m'Merge key-branch and feature/3-key'
git checkout develop
git checkout -b release/1.0
git branch develop
git merge key-branch
git push origin develop
git checkout release/1.0
git merge develop
git commit -m'Merge develop to release/1.0'
git add quest7.sh
git push origin release/1.0

