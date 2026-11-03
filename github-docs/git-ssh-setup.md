# Git over SSH Setup (Rocky 10 + GitHub)

## 1. Check for an existing key

```bash
ls ~/.ssh/*.pub
```

If you see something like `id_ed25519.pub`, you can reuse it. Otherwise create one:

```bash
ssh-keygen -t ed25519 -C "you@example.com"
```

Accept the default path. Setting a passphrase is optional.

## 2. Upload the public key to GitHub

With the `gh` (Github) CLI:

```bash
gh auth refresh -h github.com -s admin:public_key
gh ssh-key add ~/.ssh/id_ed25519.pub --title "rocky10"
```

Or paste the contents of `~/.ssh/id_ed25519.pub` into GitHub under
**Settings > SSH and GPG keys > New SSH key**.

## 3. Test the connection

```bash
ssh -T git@github.com
```

The first time, confirm GitHub's host fingerprint by typing `yes`. Success looks like this:

```
Hi USERNAME! You've successfully authenticated, but GitHub does not provide shell access.
```

## 4. Point your remote at the SSH URL

```bash
git remote set-url origin git@github.com:YOURUSER/YOURREPO.git
git remote -v
git push -u origin main
```

If the remote doesn't exist yet, use `git remote add origin ...` instead of `set-url`.

## Troubleshooting

### `Permission denied (publickey)`

The key isn't loaded or isn't on your GitHub account.

```bash
eval "$(ssh-agent -s)"        # only if ssh-agent isn't running
ssh-add ~/.ssh/id_ed25519
ssh -vT git@github.com        # shows which keys are being tried
```

### Wrong key offered (multiple keys)

Add to `~/.ssh/config`:

```
Host github.com
    IdentityFile ~/.ssh/id_ed25519
    IdentitiesOnly yes
```

### Rocky 10 / SELinux and permissions

If key files were copied in from elsewhere, restore their SELinux context and fix permissions:

```bash
restorecon -R ~/.ssh
chmod 700 ~/.ssh
chmod 600 ~/.ssh/id_ed25519
chmod 644 ~/.ssh/id_ed25519.pub
```

## Push rejected: `non-fast-forward`

SSH is working if you see this. It means the GitHub repo has a commit your local
`main` doesn't (often a README, .gitignore, or license created by `gh repo create`).

Inspect first:

```bash
git fetch origin
git log --oneline origin/main
```

Then choose one:

**A. Merge (keeps everything)**

```bash
git pull --no-rebase origin main --allow-unrelated-histories
git push -u origin main
```

**B. Rebase (linear history)**

```bash
git pull --rebase origin main
git push -u origin main
```

**C. Overwrite the remote** (discards whatever is on GitHub's `main`)

```bash
git push -u --force origin main
```

If a pull reports a conflict, edit the conflicted file, then `git add .` and
`git commit` (merge) or `git rebase --continue` (rebase) before pushing.
