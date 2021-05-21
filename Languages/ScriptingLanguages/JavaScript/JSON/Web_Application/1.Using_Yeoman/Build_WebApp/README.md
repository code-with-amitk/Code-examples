## [Building small Web Application using Yeoman](https://yeoman.io/codelab/)

### 1. Setup development env on Window
```console
//Install nodejs on windows, npm(package manager) is installed with nodejs
> npm --version
> npm install --global yo       //Install yeoman using npm
> yo --version
> npm install --global generator-fountain-webapp    //Install generator webapp
```
### 2. Install fountain-webapp depedencies using yo
- **Generator?** Is module which helps in generating something.
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
### 3. Check what files generated
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

### 3. Start & Access http server
```console
# cd C:/Users/amit/yo-proj/
> npm run serve
//Access Web Application via Browser      http://localhost:3000
```
