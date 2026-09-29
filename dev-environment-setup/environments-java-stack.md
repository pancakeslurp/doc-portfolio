# Setting up a Java development stack

# Background

## Purpose

The purpose of this process is to set up a professional-grade Java development stack. I framed this around development for national defense and contracting.

I initiated this setup because Oracle Academy, in the class Java Foundations, recommends setting up an Oracle Cloud Trial Account to instantiate virtual machines for the exercises. This is perfectly valid, but I needed to either work locally or instantiate an AWS EC2 instance to align the tasks with practice for my college classes.

## Assumptions

This document assumes you are running RHEL or Rocky 10. One step includes a caveat if you are running RHEL 9.

I ran this in a VM using VMWare Workstation. My fallback plan is to use a laptop with Rocky installed natively if VMWare fails again.

## The Stack

The stack includes the following:

- __SDKMAN!__: Helps developers manage parallel versions of multiple SDKs.
- __JDK 21 (LTS)__: Java Development Kit 21 (LTS). I chose JDK 21 for future integration with Spring Boot, the latest version of which was known to be compatible as of the time of this writing.
- __Apache Maven__: A build automation tool that simplifies and standardizes Java project builds.
- __JUnit 5 + Mockito__: Testing framework that you can use to write and run unit tests (JUnit 5) and mocking framework to simulate dependencies so you can test code in isolation (Mockito)
- __Eclipse-Temurin__: Open-source, high-performance Java SE runtime built on OpenJDK. Designed for secure, enterprise-ready, cross-platform use.
- __VS Code__: The IDE. You can also use Eclipse, Netbeans, IntelliJ IDEA, or any IDE of your choice. Occasionally I use Vim for quick and diryt, but using Notepad or GNOME Text Editor doesn't make you a lesser person.
- __Git__: Version control system.

# The Steps

## 1. Prerequisites and Git

The first step is to update the system, then install git and other prerequisites for SDKMAN!

```
sudo dnf update -y
sudo dnf install -y git curl zip unzip tar
git --version # Validates that Git is properly installed
```

We install zip and unzip because they're required by SDKMAN!

Next, configure Git. You can use your name if you want, but be careful with your email address: if you use your real email address, you're exposing it with every Git commit that you post to Github.

```
git config --global user.name "Your Name"
git config --global user.email "you@example.com" # Replace with your Github private relay address
git config --global init.defaultBranch main
```

## 2. SDKMAN!

```
curl -s "https://get.sdkman.io" | bash
source "$HOME/.sdkman/bin/sdkman-init.sh"
sdk version
```

The installer appends an init block to ~/.bashrc so that new terminals will pick it up automatically. If ```sdk version``` returns blank, close the terminal and open a new one.

## 3. JDK 21 (LTS)

Search for the version of JDK to install and install it.

```
sdk list java | grep -E "21\.[0-9.]+-tem" # Searches for available versions of Eclipse-Temurin
sdk install java <identifier from the list> # e.g. 21.0.x-tem (Eclipse Temurin)
```

If any of the next three commands return blank, close the terminal and open a new one again.

```
> java -version
> javac -version
> echo $JAVA_HOME
```

## 4. Maven

Install Maven:

> sdk install maven
> mvn -version

`mvn -version` should show Java 21 as the runtime. If not, your `$JAVA_HOME` isn't pointing at the SDKMAN JDK.

5. Project with JUnit 5 + Mockito

```
mkdir -p ~/dev && cd ~/dev # This project is going to be in `dev` in your home folder.
mvn archetype:generate -DgroupId=com.example -DartifactId=demo \
  -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
cd demo && git init # Create a git repository
```

Replace `pom.xml` with this:

```
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
  <modelVersion>4.0.0</modelVersion>
  <groupId>com.example</groupId>
  <artifactId>demo</artifactId>
  <version>1.0-SNAPSHOT</version>

  <properties>
    <maven.compiler.release>21</maven.compiler.release>
    <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
  </properties>

  <dependencies>
    <dependency>
      <groupId>org.junit.jupiter</groupId>
      <artifactId>junit-jupiter</artifactId>
      <version>5.11.4</version>
      <scope>test</scope>
    </dependency>
    <dependency>
      <groupId>org.mockito</groupId>
      <artifactId>mockito-core</artifactId>
      <version>5.14.2</version>
      <scope>test</scope>
    </dependency>
    <dependency>
      <groupId>org.mockito</groupId>
      <artifactId>mockito-junit-jupiter</artifactId>
      <version>5.14.2</version>
      <scope>test</scope>
    </dependency>
  </dependencies>

  <build>
    <plugins>
      <plugin>
        <artifactId>maven-surefire-plugin</artifactId>
        <version>3.5.2</version>
      </plugin>
    </plugins>
  </build>
</project>
```

Check Maven Central for the latest versions of the three dependencies and surefire plugin.

The surefire plugin is what actually runs the JUnit 5 tests during mvn test.

Replace the default test with a smoke test at `src/test/java/com/example/SmokeTest.java`. Delete AppTest.java because that's used by JUnit 4.

`SmokeTest.java`

```
package com.example;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

import java.util.List;
import org.junit.jupiter.api.Test;

class SmokeTest {
    @Test
    void mockitoWorks() {
        @SuppressWarnings("unchecked")
        List<String> list = mock(List.class);
        when(list.get(0)).thenReturn("hello");
        assertEquals("hello", list.get(0));
    }
}
```

Run the smoke test:

`mvn clean test`

You should see: `BUILD SUCCESS` and `Tests run: 1, Failures: 0`. In newer JDKs, Mockito might print warnings about dynamically loading an agent. The fix is a surefire `argLine` config if you need to get rid of the message.

## 6. VS Code

Look, this process is copied verbatim from this link:

`https://code.visualstudio.com/docs/setup/linux`

Step 1: Install the key and the yum/dnf repo:

```
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc &&
echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\nautorefresh=1\ntype=rpm-md\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" | sudo tee /etc/yum.repos.d/vscode.repo > /dev/null
```

Update the package cache and use DNF to install:

dnf check-update &&
sudo dnf install code # or code-insiders

I forewent the steps for older versions of RHEL/Rocky. This tutorial targets RHEL 10/Rocky 10.

Open VS Code from a terminal with SDKMAN loaded:

```
cd ~/dev/demo
code .
```

If you run it from the Gnome launcher, it might not inherit `$JAVA_HOME`.

Now, commit your baseline:

```
printf "target/\n.vscode/\n" > .gitignore # Ignore VS Code files when running git commit
git add . && git commit -m "Initial Maven project with JUnit 5 and Mockito"
```

## Day-to-Day Commands

Your routine git commits will follow this pattern:

```
git add -A
git commit -m "Your descriptive and highly informative commit message"
git push
```

# Troubleshooting

## 1. If you installed any of the packages before installing SDKMAN! and now want to use SDKMAN! to manage them:

1. See which packages are installed.

```
rpm -qa | grep -Ei 'temurin|openjdk|maven|jdk|jre'
which -a java javac mvn
echo $JAVA_HOME
```

Take note of the exact package names. Also pay attention to OpenJDK packages because Maven might have automatically pulled them in as dependencies.

2. Remove the packages

```
sudo dnf remove maven temurin-21-jdk 'java-*-openjdk*'
```

3. Remove the Adoptium repo

You might have added the Adoptium repo in order to install the base Eclipse-Temurin package.

```
ls /etc/yum.repos.d/ | grep -i adoptium # Search to see if you added the repo. \
  # Skip the next two commands if you didn't add the Adoptium repo.
sudo rm /etc/yum.repos.d/adoptium.repo
sudo dnf clean all
```

4. Check for leftover Java pointers

`alternatives --list | grep -E 'java|javac|mvn`

If you already removed Java and Maven, the output from this command will be blank.

5. Clear environment variables

grep -nE 'JAVA_HOME|M2_HOME|MAVEN_HOME' ~/.bashrc ~/.bash_profile ~/.profile 2>/dev/null
grep -rnE 'JAVA_HOME|M2_HOME|MAVEN_HOME' /etc/profile.d/ /etc/environment 2>/dev/null

Delete or comment any lines you find with these environment variables

* JAVA_HOME
* M2_HOME
* MAVEN_HOME

6. Verify that the packages are gone

Open a terminal and run:

```
which java javac mvn # should be blank
echo $JAVA_HOME # should also be blank

7. Keep or remove `~/.m2`

`rm -rf ~/.m2`

8. Install SDKMAN!

Go back to step 2 of the tutorial and resume setup.
