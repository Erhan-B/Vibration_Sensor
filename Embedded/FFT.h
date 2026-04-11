#ifndef FFT_H_
#define FFT_H_

const double esp32Voltage = 3.3;

class FFT {
    public:
        FFT();
    
    private:
        float calcGForce(int adcValue);
};

#endif /* FFT_H_ */