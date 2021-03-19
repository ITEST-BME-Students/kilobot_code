import glob
from os import path
import natsort
from moviepy.editor import *
from moviepy.audio.fx.volumex import volumex
files = glob.glob("./raw/batch*/*.webm")
files = natsort.natsorted(files)
previous_batch = 'xxx'
batch_counter = 0

for input_file in files:
    # Process file name
    current_batch, base = path.split(input_file)
    wd, current_batch = path.split(current_batch)
    base, ext = path.splitext(base)
    label = current_batch + ': ' + base

    print(current_batch, wd, base, ext)

    if previous_batch != current_batch:
        batch_counter = 0
    else:
        batch_counter = batch_counter + 1

    previous_batch = current_batch

    # New file name
    current_experiment = current_batch
    current_experiment = current_experiment.replace('batch','experiment')
    output_file = 'videos/' + current_experiment + '_' + str(batch_counter) + '.mp4'

    # Read in video
    clip = VideoFileClip(input_file)

    # Resize
    clip = clip.resize(width=450)

    # Mute audio
    #audio = clip.audio
    #audio = audio.fx(volumex, 0)
    #clip = clip.set_audio(audio)

    # Create label
    txt_clip = TextClip(label, fontsize = 14, color = 'black')
    txt_clip = txt_clip.set_pos((10, 10))
    txt_clip = txt_clip.set_duration(clip.duration)

    # Overlay the text clip
    clip = CompositeVideoClip([clip, txt_clip])


    clip.write_videofile(output_file, fps=15, audio=False)
