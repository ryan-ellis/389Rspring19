# Crypto II Writeup

Name: Ryan Ellis
Section: 0201

I pledge on my honor that I have not given or received any unauthorized
assistance on this assignment or examination.

Digital acknowledgement: Ryan Ellis

## Assignment Writeup

### Part 2

Level 1: Hello, world of XSS

- Knowing that the goal is to get a JS alert() function to pop up, I'll start by researching how the alert() method is usually called
- It appears as though the alert() method is simply called by using alert("text here"), next I will research how to actually call the method with some js
- Genearlly when working with js in html you have to include the <script> tag, so I will try to find a way to execute the script tags by using the search bar
- By writing "<script>alert("hello")</script>" I was successfully able to execute the alert dialog menu

Level 2: Persistence is key

- Since the description talked about the importance of client-side vs server-side databases. My first thought is to find a way to incorporate the script tag I used on the previous problem with some kind of post/get request to the server
- After playing around with the app, maybe I can inject the dialog box into one of the buttons so that when it sends a request to clear the messages it will also pass along the dialog box
- I got a little stuck so I opend up the first two hints and decided to take a different approach with using an element with js attributes instead
- After some research I found a method called insertAdjacentHTML() which sounds promising for injecting some js code
- I tried something like <code>var h = document.getElementById("post-form");
h.insertAdjacentHTML("afterend", "<script>alert("hello")</script>");</code> but it doesn't actually interact with the html
- Now I tried <code>document.getElementById("header").insertAdjacentHTML("afterend", "<script>alert("hello")</script>")</code> but still no luck
- I read the third hint which seems to point towards using an img along with "onerror", I'm not sure what that means so I'm going to do some research
- Apparently something like <img src="image.gif" onerror="myFunction()"> can be used to execute js which seems like something that will be perfect for this challenge
- Tried using <code><img src="https://picsum.photos/536/354" onerror="alert("hello")"></code> but still no luck
- I missed something obvious which is that the onerror will only execute if the image is invalid, so I used this instead but it still didn't work <code><img src="invalid_picture" onerror="alert("hello")"></code>
- I learned that you are not supposed to use quotes around the onerror part so this bit of code now works <code><img src="invalid_picture" onerror=alert("hello")></code>

Level 3: That sinking feeling

- Based off the problem description, there are no inputs on the site so we have to find a way to edit the website's address in order to execute our js
- At first glance it appears that this problem will be similar to the last since there appears to be an emphasis on the images of the site
- One thing that sticks out is the # in the url address that changes based on what image is being shown. I plan to research what this is used for and see if it can be exploited.
- After reading [this](https://stackoverflow.com/questions/16933700/what-does-link-href-do) it appears as though the # takes the place of the images url/source so maybe I will be able to use the same strategy from the last problem with the onerror
- I tried changing the url in the browser to "https://xss-game.appspot.com/level3/frame#1 onerror=alert("hello")" but it did not produce the desired result, will investigate further
- I think that my general approach is correct but the way I am formatting my url is wrong, I'm going to look up how to format onerror in a url to see if there are examples
- I tried reading the hints but I didn't find anything too useful
- I realized that I had to wrap the actual alert function in quotes which is strange because I didn't have to do that in the last problem, but hey it works
"https://xss-game.appspot.com/level3/frame#1' onerror='alert("hello")'>"

Level 4: Context Matters

- Looking at the code using the toggle option, I can see that the actual create timer function uses a GET request in order to process the user input
- In the timer.html file I can see that within the script tag there is a function called "startTimer" which could potentially be exploited
- Feeling a little stuck, so I'm going to take a look at the hints
- Following one of the hints I entered a single quote and found that in the console there was a "Uncaught SyntaxError: missing ) after argument list" error
- I tried changing the url to "https://xss-game.appspot.com/level4/frame?timer=3;alert('hello'" but still was not able to get the alert to work. I feel like I'm on the right track but need to find out how to format it correctly. I know that if you use a single ' it will produce a ) for you in the error log so I think I am close
- Tried "https://xss-game.appspot.com/level4/frame?timer=';alert('hello'" but still no luck. I'm going to look more closely at the startTimer method to see how I should format this
- Instead of editing the url directly I went back to entering a single quote in the input dialog. I found that by adding the ) after the quote this meant that when the input was executed it would add another ) to the end of the statement even though I already put one there manually. Thus I could attach my alert box with a ; in order to get it to execute correctly. Thus the final url is "https://xss-game.appspot.com/level4/frame?timer=');alert('hello"

Level 5: Breaking Protocol

- So from the looks of it there is another input box and based off of the description of the problem it looks like we need to find a way to inject a completely new element in the document somehow. 
- This kind of reminds me of a potential idea I had earlier which lead me to read about the insertAdjacentHTML() method which we could potentially use here
- I noticed that looking through the code, the input tag that is used to record the email has an empty value parameter which maybe we can fill with our own alert script
- After reading through the hints I've come to the conclusion that instead of trying to inject code through the actaul html I should be focusing on the actual url instead
- Tried using "https://xss-game.appspot.com/level5/frame/signup?next=alert("hello")" but it did not work, I think I am on the right track with my line of thinking though
- I realized I needed to put "javascript:" in order to signal that I'm trying to exectue js code, thus "https://xss-game.appspot.com/level5/frame/signup?next=javascript:alert(%22hello%22)"

Level 6: Follow the Rabbit

- This level appears a lot different than others simply due to the fact that there are no inputs on the site 
- Looking at the code it looks like gadget.js is not actually doing anything so our attention should be focused on index.html instead
- Not making much progress yet so I'm going to try and read the hints to see if I can get a general direction for what I should be focusing on
- So it appears that we should be focusing again on the URL and perhaps uloading our own file to load on the page instead of gadget.js
- One interesting thing about the includeGadget function is that it doesn't actually appear to escape the url or at least the comment regarding "evil URL's seems suspect"
- Along with another hint about hosting your own content, I imagine the solution involves redirecting the URL to what it thinks is an image but is actually some javascript code for us to enable our alert function.
- Awww so I see that the includeGadget function only checks for lowercase "https" which means if I simply put it in call caps I can include any link I want
- Instead of hosting my own content I'm going to use the example from the hint and use google's own link to help inject the alert box resulting in the final url of: "https://xss-game.appspot.com/level6/frame#HTTPS://www.google.com/jsapi?callback=alert" which completes the challenge!


