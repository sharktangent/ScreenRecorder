#ifndef _VIDEO_STREAM_H_
#define _VIDEO_STREAM_H_

#include "MediaStream.h"

// video_Stream responsible for handling input and output of recording video
class Video_Stream : public Media_Stream
{
public:
    // constructor
    Video_Stream();
    // destructor
    ~Video_Stream();
    // open input responsible for connecting the screen with ffmpeg
    void open_input(std::string framerate) override;
    // capture frame repsonsible for writing frames to the output file
    void capture_frame(std::string framerate) override;
    // create_outfile responsible for creating a file that can be written to
    void create_outfile(std::string bitrate, std::string framerate, std::string format) override;
    // interrupt stream responsible for setting variable to interrupt a thread
    void interrupt_stream() override;

private:
    // each component of the video stream needs input and output
    // codecs
    AVCodec* codec;
    AVCodec* out_codec;
    // codec context
    AVCodecContext* out_codec_context;
    AVCodecContext* codec_context;
    // format
    AVInputFormat* in_format;
    AVOutputFormat* out_format;
    // format_context
    AVFormatContext* format_context;
    AVFormatContext* out_format_context;
    // frame
    AVFrame* frame;
    AVFrame* out_frame;
    // packet
    AVPacket* packet;
    // stream
    AVStream* input_stream;
    // recording options
    AVDictionary* recording_options;
    // stream index finds the index of the video stream
    int stream_idx;
    // variable controls the interrupt for the recording thread.
    bool interrupt;
};

#endif