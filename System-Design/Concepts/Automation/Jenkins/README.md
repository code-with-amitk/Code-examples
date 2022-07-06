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
$ java -j jenkins.war

//Open jenkins in browser
http://localhost:8080
```

## Create [CI/CD](/System-Design/Concepts/CI-CD/) Pipeline
<a name=c1></a>
### 1. Write script in jenkins
```c
//1. Install Orchestration Pipeline plugin

//2. Go to Option > Pipleline > Definition(Pipeline) 
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

//3. Save > Build(On Left side bar)

//4. Dashboard > Pipeline_Name > Stage View
```
<img src=build_test_deploy.PNG width=500 />

### 2. Pull script from github (SCM)
