ffmpeg -y -i VID_20240225_162830.mp4 -t 5.00 -vf "fps=10,scale=-1:512:flags=lanczos,transpose=2,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse" -preset veryslow test.gif
