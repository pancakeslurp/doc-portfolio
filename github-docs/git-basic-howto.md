# Git basic how-to

## Git initial setup
```
git config --global user.name "Your Name"
git config --global user.email "you@example.com" # Replace with your Github private relay address
git config --global init.defaultBranch main
```

## View git configuration

```
git config --lists
```

## Set up a new Github repo from CLI

1. Navigate to your project folder.
2. Initialize the repository using the `-b main` flag to set the defailt branch name.
```
git init -b main
```
3. Create or addd your project files and stage them for tracking:
```
touch README.md
git add .
```
## Download an existing repo

1. Get the repo address from GitHub by clicking the green **code** button and copy the SSH URL.
*Because we all know that you've already set up an SSH token (ಠ_ಠ)*
2. Clone the repo:
```
git clone git@github.com:pancakeslurp/doc-portfolio.git
```
