#include <iostream>

class MediaPlayer {
public:
    virtual void play(std::string audioType, std::string fileName) = 0;
};

class AdvancedMediaPlayer {
public:
    virtual void playVlc(std::string fileName) = 0;
    virtual void playMp4(std::string fileName) = 0;
};

class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(std::string fileName) override {
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }

    void playMp4(std::string fileName) override {
        // 不做任何操作
    }
};

class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(std::string fileName) override {
        // 不做任何操作
    }

    void playMp4(std::string fileName) override {
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }
};

class MediaAdapter : public MediaPlayer {
private:
    AdvancedMediaPlayer* advancedMusicPlayer;

public:
    MediaAdapter(std::string audioType) {
        if (audioType == "vlc") {
            advancedMusicPlayer = new VlcPlayer();
        } else if (audioType == "mp4") {
            advancedMusicPlayer = new Mp4Player();
        }
    }

    void play(std::string audioType, std::string fileName) override {
        if (audioType == "vlc") {
            advancedMusicPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            advancedMusicPlayer->playMp4(fileName);
        }
    }
};

class AudioPlayer : public MediaPlayer {
private:
    MediaAdapter* mediaAdapter;

public:
    void play(std::string audioType, std::string fileName) override {
        if (audioType == "mp3") {
            std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
        } else if (audioType == "vlc" || audioType == "mp4") {
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, fileName);
        } else {
            std::cout << "Invalid media. " << audioType << " format not supported" << std::endl;
        }
    }
};

int main() {
    AudioPlayer audioPlayer;

    audioPlayer.play("mp3", "beyond the horizon.mp3");
    audioPlayer.play("mp4", "alone.mp4");
    audioPlayer.play("vlc", "far far away.vlc");
    audioPlayer.play("avi", "mind me.avi");

    return 0;
}