# Guidelines To Contributing

Before you get started, there are a few things you must have knowledge of, as well as few things you must have installed:
1. Prerequisite Knowledge
    - C++ or adequate experience in similar languages
    - Experience with Development Boards, or relevant electrical knowledge
2. Prerequisite Tools
    - Git & Github account(*required for collaboration*)
    - Arduino Compiler (*to compile the project*)
        - Use Arduino IDE or PlatformIO extension on VS Code

Given the above is met, you can contribute via following the steps below

## Getting Your Own Copy of the Repository

This step involves forking the original repository onto your own profile and then cloning it locally.

### Forking

1. Sign in with your Github account
2. Open this repository page ([link](https://github.com/execphantasmagoria/ESP32MarauderOLED_BN))
3. Click on "Fork" button, then leave the default settings as is, then green button "Create Fork"

You should have a copy of the repository on your profile now. This is where you will push your changes and additions of code to.
To start making changes, clone the repository to get a local copy on your PC.

### Cloning

1. Copy the clone link. Click on green button "<> Code", then under HTTPS, click the copy button and get the link. It should be something like `https://github.com/yourusername/repo-name.git`
2. Open command prompt and navigate to a folder in the PC where you want to store the project. Use the command `cd` to navigate.
3. Clone the repository there via: `git clone --recursive https://github.com/yourusername/repo-name.git`.

You now have a local copy of your repository.

## Making Changes

Once you have your local copy, open it in your preferred code editor (assuming VS Code). Before you make any changes, you should first fetch all the branches from upstream repository, so that you may work on the correct branch. Run the following commands from the integrated terminal, or the Windows' Command Prompt to do so:
```bash
git fetch --all
```

Now, view the branches and switch to a branch you want to work upon via:
```bash
git branch
git switch branch-name
```

(Optional) If you are working on a new feature, or modifying code of a branch, it is good practice to create a new branch with a name suitable for what you will be working upon. For example, if you want to add a new menu called 'WiFi Menu', you should create and switch to a new branch called `wifi-menu-feature`. Do so via:
```bash
git switch -c wifi-menu-feature
```

Then you may make all the necessary changes and additions.

## Verifying Changes

Before you commit a set of changes, verify that the code compiles correctly. Open the `esp32_marauder.ino` file in Arduino IDE, then click the 'Tick' button to compile the code. If the code compiles without any issue, commit the changes.

*NOTE: If you have freshly installed Arduino, you will have errors as you will need to install a bunch of libraries into Arduino for the project to work. If you are unsure how to fix a library include error, or other compilation errors, contact me.*

## Committing & Pushing Changes

This step is where changes are uploaded on Github.

### Committing

After making a set of changes, you can use the integrated Source Control view or manually add the modified files and commit the changes. Do so via
```bash
git add .
git commit -m "short, one-line description of changes"
```

You may need to set the user configuration before committing. Namely, your Github username and Github email address. Follow the relevant instructions from output or online to set that up.

### Pushing

Try not to group too many unrelated changes under the same commit. Keep commit messages short but descriptive enough. Real description can await the comments on pull request. Once you are done with all your changes and have commited them locally, push the changes to your own repository. Do so via:
```bash
git push origin <branch-name>
```

You may need to sign in using your token if it is your first time. Enter the username when prompted but for password, follow relevant guides online to generate a token and use it in place of the password.

Once all the changes have been made and pushed, send forth a Pull Request.

## Merging

Use the Github UI on browser (or extension if preferred) to send a pull request. Follow the steps below to do so:
1. Click on the "Contribute" button on your repository page
2. Open pull request
3. Keep the base repository as-is, change the base master to match the branch you were editing on, then choose which branch on your repository you want to be merged.
4. Give an adequate title and summary of all the changes
5. Create pull request

After this, await for me to review, verify and merge the changes.