<p align="center">
<img src="https://dwm.suckless.org/dwm.svg" alt="dwm Logo"/>
</p>
<p> &emsp; </p>


<h1>Patching and recompiling dwm</h1>
Using a .diff for patching then recompiling with a makefile.<br />
<p> &emsp; </p>



<h2>Video Demonstration</h2>

- ### [YouTube: Patching dwm](https://youtu.be/lgpd8V6RW6M)
<p> &emsp; </p>


<h2>Requirements</h2>

- make (GNU)
- patch (GNU)
- dwm
<p> &emsp; </p>


<h2>Operating Systems Used </h2>

- Arch Linux
<p> &emsp; </p>


<h2>High-Level Configuration Steps</h2>

- Find a patch to apply
- Save it in dwm directory
- Patch
- Correct any failures
- Recompile
<p> &emsp; </p>


<h2>Configuration Steps</h2>

<p>
<img src="https://i.imgur.com/JGPzRXV.png" height="80%" width="80%" alt="suckless"/>
</p>
<p>
- Navigate to the suckless website and find the patches link in the dwm subsection.<p></p>
- Save the .diff file for the patch you want to your dwm source directory.<p></p>
- Inside the dwm dir run "patch -p1 < (filename.diff)" to apply the patch. (-p1 means use current directory.)<p></p>
  
>A patch can also be reverted using "-R" instead of "-p1".
</p>
<br />
<p> &emsp; </p>
<p> &emsp; </p>

  
<p>
<img src="https://i.imgur.com/nrFgytw.png" height="80%" width="80%" alt="patch-attempt"/>
</p>
<p>
- The output of the command will show if there were any lines that failed to be applied.<p></p>
- Failed additions and/or subtractions will be saved to a .rej file based on the target file's name.<p></p>

>Failure to apply a line in "config.h" will produce a "config.h.rej" file.
</p>
<br />
<p> &emsp; </p>
<p> &emsp; </p>



<p>
<img src="https://i.imgur.com/laCIzIC.png" height="80%" width="80%" alt="patching_rej"/>
</p>
<p>
- Open the target file and the .rej file (preferably side by side).<p></p>
- The .rej file will indicate any additions (+) or subtractions (-) it attempted on the target file.<p></p>
- In the picture above we see an attempt to remove, and add a line, amounting to a simple value change.<p></p>
- After working the change into the target file, the .rej (and .orig) file can be deleted.<p></p>
</p>
<br />
<p> &emsp; </p>
<p> &emsp; </p>



<p>
<img src="https://i.imgur.com/qX3ZZSx.png" height="80%" width="80%" alt="end-result"/>
</p>
<p>
- With the changes saved we can move onto recompiling dwm.<p>
- dwm is built with a makefile (and a config.mk file) directing the paths and CFLAGS to be used.<p></p>

>Editing these files will likely never be necessary but they can be viewed in the source repo.<p>
<p> &emsp; </p>


<p>- Inside the source directory we run "sudo make uninstall", uninstalling the version of dwm we are currently running.<p>

>using sudo since we are modifying/installing files under the root directory. [/usr/local/]
<p> &emsp; </p>
- Then run "sudo make clean install", cleaning up any leftover .rej/.orig files and recompiling dwm.<p></p>
- We see the "fake-fullscreen" patch successfully installed, confining a "fullscreen" video to its own window space.
<br />
