# The idea
we have a normal template which has syntax somewhat similar to pug/jade. Through template we can express interpolations for loops if etc.

# How the templates are going to be interpreted ?

Basically I have an Idea in my mind. we're gonna convert/transpile templates into chaiscript functions. So where conditions or loops are there we could actually replace it with chaiscript loops. lemme consider an xml template here
```jade
box(*if="somecondition", style="background:red;width:100px;height:100px") hello 
```

the above tag is prolly gonna look like this after converting it.

```javascript
fun draw(){
    if(somecondition){
        random_id = new Box(); //box is widget
        {
            random_id.width = 100;  
            random_id.height = 100;
            random_id.background = Color("red");
        }
    }
    ...
}
```
and the this function will the member of the component class in which the template is defined. like in `Angular` we write component. let's see an example how interpolation and variables are shared.

```jade
text(style="color:red") hello {{mytext}} 
```

the equivalent code version will be

```javascript
fun draw(){
    randm_id = new Text()
    random_id.text = "hello" + this.mytext
    ...
}
```

hope fully that gives an idea about how all all features will be organised

# context
let's consider the template below
```jade
box(style="width:100px;height:100px")
    text hello world!
    text blah
```
here the job is to write the text inside of the box for doing this job I think it's better to mainatain an AST
where it will probably look like this.
```
        (root)
          |
        (box)
        /   \
    (text) (text)

``` 

optimization of AST is later part

# status

working on it. Parser code may be ugly. It won't hurt much coz we're not gonna read template many times!

# todo
code to
  - generate draw function for each components
  - generate AST

  