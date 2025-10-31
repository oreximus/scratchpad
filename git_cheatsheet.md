# Git Cheetsheet

- for saving the current state of the project, to where we can undo,
  if something goes wrong:

```

```

- to sync up the current selected branch with the main branch:

```
git merge origin/main
```

- to fetch all of the remote branch locally:

```
for branch in $(git branch -r | grep -v "\->" | grep -v HEAD | grep origin/); do git branch --track "${branch#origin/}" "$branch" 2>/dev/null || true; done
```
