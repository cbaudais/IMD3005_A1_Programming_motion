﻿### Open Frameworks Project 
-> Project files must be (re)generated with the <a href="https://openframeworks.cc/learning/01_basics/create_a_new_project/">OF projectGenerator</a> to run.

<code>Christina Baudais
<br>
<br>
Overview:
<br>
I created and underwater "orbiting" system, with jellyfish surrounding a cluster of bubbles/sea foam, and more bubbles orbiting the jellyfishes.  I also added a little submarine to move around and two divers to trail it.  You can also use the arrow keys to change the bkg/vibe or the place. Overall the trail is what really made this a challenge, the rest took some time but ultimately the code we had helped.
<br>
<br>
Challenges:
<br>
Since I've never used OpenFrameworks before, and the fact that syntax is my biggest nemesis, the biggest challenge was figuring out how to make things work using code (mainly the trail).  Another problem is that my images are one way, and I would have liked to have them flip when changing direction...I just didn't have time when I noticed I should do that.
There's also making the jellyfish point in the direction it is moving towards when in orbit.  Took lots of meddling with the numbers to eventually figure out a good combo.
Somehow was a lot harder to get the "moons" orbiting the "planets", aka the bubbles to the jellyfish.
<br>
WORST part was the trail; I don't know how many times I changed multiple things (desperate) but nothing worked. I tried every suggestions.
<br>
<br>
What went well:
<br>
Once I got the theme idea of underwater it was easy to pick what were the orbiting things.  Drawing my elements was fun as well, but sometimes I think I should have stuck to basic planets to get more time to code...oh well.  For the image flip...well you're just seeing a view from the top ¯\_(ツ)_/¯ haha. I did modify the submarine image for it to work in all direction, and it ended up looking 10x better than the original drawing.  The divers are still facing right however.  The orbiting bubbles and jellyfish I ended up making a chunk of code the child, then put draw moon inside it (making it child's child), but that took forever for me to figure out, I kept wanting to try a "drawmoon" inside a matrix with "previous drawmoon", and for some reason it wouldn't exactly work flawlessly.
<br>
And the trail....I eventually got something close enough, and by making the numbers in leap really small, it had a trail like effect.  Cant figure where to offset diver more behind the submarine but this is good enough.
</code>


https://github.com/cbaudais/IMD3005_A1_Programming_motion/assets/97922886/c38d33ca-b78e-4d99-98b3-9e115e446b82


![screenshot](Screen_Shot_2021-09-27.png)