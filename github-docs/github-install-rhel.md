# Installing Github repos in RHEL/Rocky

## Installing Github CLI
### 1. Update the system
```
sudo dnf upgrade --refresh
```

### 2. Add Github CLI repo
```
sudo dnf install 'dnf-command(config-manager)' -y
sudo dnf config-manager --add-repo
https://cli.github.com/packages/rpg/gh-cli.repo
```

### 3. Install Git + Github CLI
```
sudo dnf install git -y
sudo dnf install gh --repo gh-cli -y
```

### 4. Verify installation
```
gh --version
```

## Logging into Github

1. Log in

```
gh auth login
```

Choose github.com or GitHub Enterprise Server

Select HTTPS or SSH for Git operations. (Save yourself the pain and use SSH, seriously.)

Authenticate with your browser or personal access token (if using HTTPS).

2. Check login status

``` 
gh auth status
```

## Common commands

Clone a repo

```
gh repo clone ownername/reponame
```

Create a pull request

``` 
gh pr create
```

List issues assigned to yourself

``` 
gh issue list --assignee @me
```

Trigger a workflow

``` 
gh workflow run workflow-name.yml
```

Create new repo from local code

```
cd ~/my-project
gh repo create
```