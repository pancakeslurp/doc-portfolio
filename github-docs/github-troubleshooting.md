# Github troubleshooting reference

# Resolving conflicts between your local repo and the Github repo

Basic command to reconcile conflicts between your local repo and the Github repo:

```
# Local version wins on conflicts
git pull --no-rebase -X ours

# GitHub version wins on conflicts
git pull --no-rebase -X theirs
```
