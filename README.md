ObjectiveGit-iOS-Example
========================

This is a quick guide on setting up ObjectiveGit for an iOS project. The example code clones a repository if it doesn't already exist, and displays the latest commit message. Don't expect much; it's only meant to get you started.

### Adding the ObjectiveGit framework to a new iOS project
1. Create a new project on Xcode (make sure to check "initialize a git repository"). Do not use spaces in the project name; the `bootstrap` script for ObjectiveGit will not work with paths with spaces
1. At the command line, `cd` into your project root, and run `git submodule add git@github.com:libgit2/objective-git.git`.
1. Make sure you have installed [Brew][2], a package manage for OSX, which the `bootstrap` script uses to pull dependencies
1. `cd` into `objective-git`, then run `./script/bootstrap`. The first build may take a while (~10 minutes)
1. Open Finder (`open .`). Drag `ObjectiveGitFramework.xcodeproj` into Xcode onto your project. Xcode may ask to "Share working copy"; just click yes; [it doesn't seem to matter][3]
1. In the "Build Phases" tab, add `ObjectiveGit-iOS-arm64` under "Target Dependencies"
1. Under "Link Binary With Binaries", add "`libObjectiveGit-iOS.a` from 'ObjectiveGit-iOS-arm64' target", `libz.dylib`, and `libiconv.dylib`
1. In the "Build Settings" tab, set "Always Search User Paths" to `YES`
1. Add `$(BUILT_PRODUCTS_DIR)/usr/local/include`, and `$(PROJECT_DIR)/objective-git/External/libgit2/include` to "User Header Search Paths"
1. Add `-all_load` to "Other Linker Flags"
1. Don't forget to `#import <ObjectiveGit/ObjectiveGit.h>` as you would with any other framework

### Cloning/Using this project as a template
1. `git clone ...`
1. `git submodule update --init --recursive`
1. `cd objective-git`
1. `./script/bootstrap`
1. In Xcode, choose "Open Other" and import the `.xcodeproj` file
1. Everything else should already be set up

### Notes
- You may have to add `GTRepositoryCloneOptionsTransportFlags: @YES` to the options of `[GTRepository cloneFromURL:...]` to disable checking SSL certificates. [This appears to be an error on the iOS simulator][4]

[1]: https://github.com/libgit2/objective-git
[2]: http://brew.sh
[3]: http://stackoverflow.com/questions/19324756/share-working-copy-in-xcode-when-adding-a-project-under-git-version-control
[4]: https://github.com/libgit2/objective-git/pull/246
