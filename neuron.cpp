#include <iostream>
#include <vector>
#include <time.h>
using std::string;
using std::vector;

class Neuron {
    float bias;
    vector<float> weights;
    string activationFunc;
    
    public:
        Neuron(int inputs, string act) : activationFunc(act) {
            assert(("Only 'relu' activation supported", act == "relu"));
            assert(("Inputs to neuron must be greater than 0!", inputs > 0));

            bias = 0;
            for (int i = 0; i < inputs; i++) {
                if ((((float) rand() / (RAND_MAX))) > 0.5) {
                    weights.push_back(((float) rand() / (RAND_MAX)));
                } else {
                    weights.push_back(-((float) rand() / (RAND_MAX)));
                }
                
            }
        }

        void print_weights() {
            for (std::vector<float>::iterator it = weights.begin() ; it != weights.end(); ++it) {
                std::cout << ' ' << *it;
                std::cout << '\n';
            }
        }

        float forwards(vector<float> inputs) {
            assert(("Input length must match inputs for neuron", inputs.size() == weights.size()));
            float ret = 0;
            vector<float>::iterator iit = inputs.begin();
            vector<float>::iterator wit = weights.begin();

            for (int i = 0; i < inputs.size(); i++) {
                ret += ((*iit) * (*wit));
                wit++;
                iit++;
            }

            ret += bias;

            if (activationFunc == "relu") {
                if (ret < 0) {
                    return 0;
                }

                return ret;
            }

            return -1;
        }
};

class NeuronLayer {
    int inputs;
    string activationFunc;
    vector<Neuron*> neurons;
    public:
        NeuronLayer(int in, int num, string act) {
            assert(("Neurons in layer must be greater than 0!", num > 0));

            for (int i = 0; i < num; i++) {
                neurons.push_back(new Neuron(in, act));
            }
        }

        int getNumberOfNeurons() {
            return neurons.size();
        }

        string getActivationFunc() {
            return activationFunc;
        }

        vector<float> forwards(vector<float> inputs) {
            vector<float> ret;
            vector<Neuron*>::iterator nit = neurons.begin();

            for (int i = 0; i < neurons.size(); i++) {
                ret.push_back((*nit)->forwards(inputs));
                nit++;
            }

            return ret;
        }
};

class NeuralNet {
    vector<NeuronLayer*> layers;
    void add_layer(int number_of_neurons, int inputs, string activationFunc) {
        layers.push_back(new NeuronLayer(inputs, number_of_neurons, activationFunc));
    }
    public:
        NeuralNet(int inputs, string activationFunc) {
            add_layer(inputs, inputs, activationFunc);
        }

        void add_layer(int number_of_neurons, string activationFunc) {
            add_layer(layers.back()->getNumberOfNeurons(), number_of_neurons, activationFunc);
        }

        float forwards() {
            //assert(("Only linear final activation supported."), (layers.back()->getActivationFunc() == "linear"));
            //assert(("Final activation layer only supports one neuron."), layers.back()->getNumberOfNeurons() == 1));

            
        }
};

int main() {
    srand(time(NULL));
    /*
    
    Neuron Test Code
    
    Neuron *n = new Neuron(6, "relu");
    n->print_weights();

    vector<float> v (6,0.4);
    std::cout << "\n" << n->out(v) << "\n";

    */

   NeuronLayer* nl = new NeuronLayer(5, 10, "relu");

}