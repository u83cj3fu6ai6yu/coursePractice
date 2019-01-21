import logging
import getpass
import sys

class PyLog(object):
    def __init__(self):
        
        self.logger = logging.getLogger()
        self.logger.setLevel(logging.INFO)
        format = '%(asctime)s - %(levelname)s : %(message)s'
        datefmt = '%Y-%m-%d %H:%M:%S'
        formatter = logging.Formatter(format, datefmt)
        
        streamhandler = logging.StreamHandler()
        streamhandler.setFormatter(formatter)
        self.logger.addHandler(streamhandler)
        
        logfile = './Log/' + sys.argv[0][0:-3] + '.log'
        filehandler = logging.FileHandler(logfile, 'w')
        filehandler.setFormatter(formatter)
        self.logger.addHandler(filehandler)
        
    def debug(self, msg):
        self.logger.debug(msg)
        
    def info(self, msg):
        self.logger.info(msg)
        
    def warning(self, msg):
        self.logger.warning(msg)
        
    def error(self, msg):
        self.logger.error(msg)
        
    def critical(self, msg):
        self.logger.critical(msg)
        
    def log(self, level, msg):
        self.logger.log(level, msg)
     