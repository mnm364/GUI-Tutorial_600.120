# GUI-Tutorial_600.120
Tutorial for web-based GUI for 600.120 class presentation

For those of you working on the GUI extra credit, here's a written up version of what I covered in the tutorial session.
All instructions are designed to be run on the ugrad servers.
 
<strong>Downloading and running the code</strong>
The code is hosted on GitHub, so downloading and running it is similar to using git for any other project.
 
<ol>
<li>Download the code by running <tt>git clone https://github.com/jedestep/htmlive</tt></li>
<li>Move into the directory by running <tt>cd htmlive</tt></li>
<li>Copy the code into your working directory: <tt>cp -r htmlive/* your_code_directory</tt></li>
<li>Go to your working directory: <tt>cd your_code_directory</tt></li>
<li>Create an output file: <tt>touch templates/out.html</tt></li>
<li>Create the in.txt file in your working directory:  touch in.txt</li>
<li>Create ready file in working directory: touch ready</li>
<li>Run the web server: <tt>python server.py your_group_number</tt></li>
<li>You should see a message "Running on 0.0.0.0:&lt;20000+your_group_number&gt;</li>
</ol>
 
Suppose you ran this on ugrad10: then you can view the page at ugrad10.cs.jhu.edu:&lt;20000+your_group_number&gt;. It should appear blank initially. This page is composed of 3 HTML files, all located in the templates directory. 
<ul>
<li><tt>base.html</tt>: contains the header. Modify this if you want to link to any CSS stylesheets.</li>
<li><tt>index.html</tt>: contains the main body of the HTML document. The content here is static.</li>
<li><tt>out.html</tt>: this is dynamic content that your program will generate.</li>
</ul>
 
Your program will generate HTML output to the <tt>templates/out.html</tt> file in order to interact with the GUI. The site should update automatically in your browser, no refresh required. Now let's talk about how the website can send data to your program.
 
<strong>Getting input</strong>
Your GUI can have the capability to send data directly from the website to your program. You need two components in place. First is at least one HTML form. You can add one like this:
<pre>&lt;form action="/" method="POST"&gt;
     &lt;input type="text" name=" " value=""&gt;	
     &lt;input type="submit"&gt;
&lt;/form&gt;</pre>
You'll need to add one or more inputs to your form in order for it to send any data. For this purpose I recommend looking up your options on <a href="http://www.w3schools.org/" target="_blank">www.w3schools.org</a> but briefly you can represent text boxes, checkboxes, radio bubbles, dropdowns and a few others. Make sure to give a "name" attribute to every input in your form; they'll be useful later. If you want the form to appear on your page every time without having to rewrite it in out.html, you can include it on index.html (outside of the userbox div).
 
Now, assuming that there are forms somewhere on your website, you can receive input. To set up your program to receive input from the site, run it with <tt>python monitor.py ./your_executable 1</tt>. When a form is submitted, inputs will be sent to your program in the following manner:
<pre>name value
name value
name value
...</pre>
The <tt>name </tt>field will be the "name" attribute from each form input, and the value will be the value inputted from the form. For text inputs it will be the text that was given; for radio buttons it will be "on" if that radio was selected; for checkboxes it will be "checked" if that value was checked. For more on this you can check out <a href="http://www.w3schools.org/" target="_blank">www.w3schools.org</a>. 
 
<strong>Summary: What should my program do?</strong>
<ul>
<li>Accept inputs of the form shown above <em>from standard input (cin)</em></li>
<li>Write HTML to the file <tt>templates/out.html</tt></li>
</ul>

<b>Overall scheme (for your sanity, you really only need to worry about the stuff outlined in blue):</b>
<b><img src="https://d1b10bmlvqabco.cloudfront.net/attach/i53zrt2c52446i/hqy5jb4xp716hn/i93ogb70nuhc/IMG_0422.JPG" width="457" height="343"></b>

<strong>Creating public files for CSS/JS/other stuff:</strong>
<ul>
<li>A useful way to host images/CSS files/other stuff is by creating a directory <tt>public_html</tt> in the <strong>home</strong> directory of your ugrad account. </li>
<li>You can use the command below to make the folder public to the world</li>
</ul>

<pre>chmod 755 public_html</pre>
<ul>
<li>You then still need to make each file within that directory public individually. This is much the same as above:</li>
</ul>
<pre>chmod 755 &lt;file&gt;</pre>
<ul>
<li>Those files will then be available publicly at <a href="http://ugrad.cs.jhu.edu/~your_account/filename">http://ugrad.cs.jhu.edu/~your_account/filename</a></li>
<li><a href="http://ugrad.cs.jhu.edu/~your_account/filename"></a><a href="http://ugrad.cs.jhu.edu/~your_account/filename" target="_blank"></a>You can link to CSS stylesheets by including them in the header section in <tt>templates/base.html</tt>. You can link them with <tt>&lt;link rel="stylesheet" href="url_of_css_file"&gt;.</tt></li>
<li>You can include images with <tt>&lt;img src="url_of_image"&gt;</tt></li>
</ul>

<b>Making HTML C++ friendly:</b>
<ul>
<li>I made a nice little java code available for you to convert nice looking HTML into nasty looking C++ acceptable strings...</li>
<li>Basically it just replaces all the newlines with actual '\n' characters and replaces the quotes with \"</li>
<li>You can find it here: <a href="https://github.com/mnm364/GUI-Tutorial_600.120.git">https://github.com/mnm364/GUI-Tutorial_600.120.git</a> (git clone as before)</li>
<li>You will find the appropriate files in the directory "htmlFormatter"</li>
<li>To compile java on the command line use the command below. This will create the file HTML_formatter.class</li>
</ul>
<pre>javac HTML_formatter.java</pre>
<ul>
<li>Then you can copy the portion of the html code you want to convert into the file "input.txt" and run the program with the command below:</li>
</ul>
<pre>java HTML_formatter</pre>
<ul>
<li>your newly formatted HTML code will be in the file "output.txt" :)</li>
</ul>

<strong>Closing thoughts:</strong>
<ul>
<li>Killing python tasks ("server.py" and "monitor.py") use the command below followed by the command after that (the PID # is the # in the labeled PID column)</li>
</ul>
<pre>ps -x
kill -9 &lt;PID #&gt;</pre>
<ul>
<li>clear "in.txt" and "out.html" b/f next run as they will retain their information (unless you clear it in your C++ code explicitly)</li>
</ul>

<strong>Appendix/Tips</strong>
<ul>
<li>Find a simple example at <a href="https://github.com/mnm364/GUI-Tutorial_600.120.git">https://github.com/mnm364/GUI-Tutorial_600.120.git</a> under the directory "tests." I will lay out the commands to run and exit this code but will not explain it much as it has been discussed throughout this tutorial</li>
</ul>
<pre>echo -n "" &gt; templates/out.html
echo -n "" &gt; in.txt

python server.py &lt;group-number&gt;
^z
bg
g++ simple.cpp -o simple
python monitor.py ./simple 1
^z
bg

ps -x
kill -9 &lt;PID # of monitor.py&gt;
kill -9 &lt;PID # of server.py&gt;</pre>
<ul>
<li>If you have a familiarity with JavaScript you can use hidden forms that are given values dynamically by user interaction with the webpage instead of users typing into text boxes.</li>
<li>If you only want the website to update once your program has run through a whole turn, consider using a temporary file to store the html generated by the program and then when your ready put that into templates/out.html as such:</li>
</ul>
<pre>outFile.open("templates/out.html");
copyFile.open("Copyfile.txt");

outFile &lt;&lt; copyFile.rdbuf();

outFile.close();
copyFile.close();</pre>
<ul>
<li>I am not sure what the deal is with the "ready" file. If you are getting errors as below then just copy the ready file from <a href="https://github.com/mnm364/GUI-Tutorial_600.120.git">https://github.com/mnm364/GUI-Tutorial_600.120.git</a> in the simple sample and put it into your working directory (don't question it :P)</li>
</ul>
<pre>Traceback (most recent call last):
  File "html/monitor.py", line 12, in &lt;module&gt;
    stats = os.stat('ready')
OSError: [Errno 2] No such file or directory: 'ready'</pre>
<ul>
<li>Broken pipes (an example shown below) generally means the child process (your program) was not alive when it tried to send input to it. So most likely your program is crashing on something, but that isn't 100% guaranteed to be the cause.</li>
</ul>
<pre>Traceback (most recent call last):
  File "monitor.py", line 18, in
  child.stdin.write(l) 
IOError: [Errno 32] Broken pipe 
</pre>
<ul>
<li>Tables are defined with the <tt>&lt;table&gt;</tt> tag. A table is a list of rows, which are defined with <tt>&lt;tr&gt;. </tt>A row is a list of cells, defined with <tt>&lt;td&gt;</tt>. For info on how to make your tables look nice and more, check out <a href="http://www.w3schools.com/html/html_tables.asp" target="_blank">http://www.w3schools.com/html/html_tables.asp</a>.</li>
<li>Bootstrap is an amazing CSS library that is available for free and is super simple. <a href="http://getbootstrap.com/" target="_blank">http://getbootstrap.com/</a></li>
</ul>
 
If there are any problems or questions please let me know right away. My office hours are on Sunday and Tuesday.

Good Luck! :D

#pin


