**Jenkins**
- [Installation](#i)
- Create CI/CD Pipeline
   - [1. Write script in jenkins](#c1)
   - [2. Pull script from github=SCM](#c2)

## Jenkins
Open source automation server which helps to build, test, and deploy the software.

## Installation
#### 1. Ubuntu
```c
//Download java. Jenkins mandatorily needs java
$ apt install openjdk-11-jre-headless

//Download jenkins.war from https://www.jenkins.io/download/

//Start jenkins without install
$ java -jar jenkins.war

//Open jenkins in browser
http://localhost:8080

Install Plugins > Manage Plugins
git, Orchestration Pipeline
```

## Create [CI/CD](/System-Design/Concepts/CI-CD/) Pipeline
[Good Video](https://www.youtube.com/watch?v=O27bMOrl3G8)

<a name=c1></a>
### 1. Write script in jenkins
```c
//1. Go to Option > Pipleline > Definition(Pipeline) 
pipeline {
   agent any

   stages {
      stage('Build') {
        steps {
          echo 'Building...'
          echo "Running ${env.BUILD_ID} ${env.BUILD_DISPLAY_NAME} on ${env.NODE_NAME} and JOB ${env.JOB_NAME}"
        }
   }
   stage('Test') {
     steps {
        echo 'Testing...'
     }
   }
   stage('Deploy') {
     steps {
       echo 'Deploying...'
     }
   }
  }
}

//2. Save > Build(On Left side bar)

//3. Dashboard > Pipeline_Name > Stage View
```
<img src=build_test_deploy.PNG width=600 />

### 2. Pull script from github (SCM)
```c
//1. Install Orchestration Pipeline plugin

//2. Dashboard > TestPipeline > Build Triggers > Pipeline > Definition(Pipeline script from SCM) 
> git
   Repository URL: https://github.com/amitkumar50/test-repo.git
   Branch : Master
   Script Path: Jenkinsfile
```
<img src=pull_from_git_build.PNG width=600 />
