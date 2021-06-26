- [1. What is Yeoman](#yeoman)
- [2. Steps of building webapp using yeoman](#steps)

<a name=yeoman></a>
## 1. Yeoman
- Yeoman helps to kickstart Web Application development helping in gluing/building userful parts.
- **Scaffold?**
  - *Dictionary Meaning?* A temporary structure on the outside of a building, made of wooden planks
  - *In Yeoman Terms?* Generating files for our web app based on specific configuration(Eg: favorite library or framework)

<a name=steps></a>
## [2. Steps](https://yeoman.io/codelab/)
- **1. Setup development env on Window**
```console
//Install nodejs on windows, npm(package manager) is installed with nodejs
> npm --version
> npm install --global yo       //Install yeoman using npm
> yo --version
> npm install --global generator-fountain-webapp    //Install generator webapp
```
- **2. Install fountain-webapp depedencies using yo**
  - *Generator?* Is module which helps in generating something.
```console
//Create Directory C:/Users/amit/yo-proj/
> cd C:/Users/amit/yo-proj/
> yo
Run generator
  Fountain webapp   <<Select
? Which Javascript framework do you want? React
? Which module management? Webpack with npm
? Which JS Preprocessor? ES2015 today with Babel
? Which CSS Preprocessor? SASS
? Do you want sample app? Redux TodoMVC
```
- **3. Check what files generated**
```console
> dir C:/Users/amit/yo-proj/
  conf                //Parent directory for our configuration files for third-party tools (Browsersync, Webpack, Gulp, Karma)
  gulp_tasks          //builder tasks
  node_modules        //configuration and dependencies required
  src                 //React + Redux code
    app
      actions
      components
      constants
      containers
      reducers
      store
      index.html      //base html file
      index.js        //Entry point for yo-proj app
      index.css
      index.spec.js   
      .babelrc        //configuration and dependencies
      package.json    //configuration and dependencies
```
- **4. Start & Access http server**
```console
# cd C:/Users/amit/yo-proj/
> npm run serve
//Access Web Application via Browser      http://localhost:3000
```
- **5. Change and see live loading**
```console
# vim yo-project/src/app/components/Header.spec.js
  //placeholder="What needs to be done?"
  placeholder="In becoming T11"
  
Content of http://localhost::3000 changes automatically. This live loading is done by gulp 

> Kill the server with Cntrl^C
```
- **6. Test Web service using Karma or Jasmine**
  - *Karma/Jasmine:* These are JavaScript test runner that tests framework.
```console
cmd> cd yo-project
cmd> npm test

Test cases are created in: src/app/reducers/todos.spec.js
```
- **7. Optimize files for Production**
  - For making code production ready, we need to:
    - *1.* concatenate and minify our scripts and styles to save on those network requests
    - *2.* compile the output of any preprocessors we’re using, and generally make our application really lean.
```js
> npm run build
```
- *3.* Production ready app is avialble in: `c:\users\amit\yo-project\dist`.
```js
> ls c:\users\amit\yo-project\dist
app-ID.js
index.html
index-ID.css
vendor-ID.js
```
- *4.* Test production app by running
```js
> npm run serve:dist

//Access using web brower http://localhost::3000
```
- *5.* Files inside `dist` can be put on your server using FTP or any other deployment service.

