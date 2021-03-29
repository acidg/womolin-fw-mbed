namespace mainunit
{

    /**
     * A command in the context of WomoLIN is an instruction which can be sent to the device
     * and triggers some routine on the device itself. This may result in change of
     * the states of the device.
     * A command does not directly return a result, but instead callers have to use the device's
     * states to check, whether the command was successful or failed and e.g. should be repeated.
     */
    template <typename T>
    class ICommand
    {
    public:
        /**
         * Routine to execute when the command is triggered.
         */
        virtual void run(T *parameters);

        /**
         * Returns a human readable description of the command
         */
        virtual std::string getDescription();
    };
}