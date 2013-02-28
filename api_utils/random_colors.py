#!/usr/bin/python
"""Lightbox JSON API Plugin to provide random colors.

This application interacts with the JSON API for Lightbox.
"""
__author__ = 'Elmer de Looff <elmer@underdark.nl>'
__version__ = '1.0'

# Standard modules
import random
import requests
import simplejson
import time


def RandomColor(saturate=False):
  """Generates a random RGB color list with at least one channel 'darkish'."""
  color = map(random.randrange, [256] * 3)
  if saturate and min(color) > 50:
    color[random.randrange(3)] = 0
  return color


def RandomColorSender(host, port, interval, layer):
  """Updates the Lightbox outputs sequentially with random colors."""
  api_address = 'http://%s:%d' % (host, port)
  while True:
    outputs = requests.get(api_address + '/api').json()['outputs']
    for output in range(outputs):
      command = {'output': output,
                 'layer': layer,
                 'color': RandomColor(),
                 'steps': 40}
      requests.post(api_address, data={'json': simplejson.dumps(command)})
      time.sleep(interval)
    print '%s: All outputs have new random colors.' % time.ctime()


def main():
  """Processes commandline input to setup the API server."""
  import optparse
  parser = optparse.OptionParser()
  parser.add_option('--host', default='localhost',
                    help='Lightbox API server address (default localhost).')
  parser.add_option('--port', type='int', default=8000,
                    help='Lightbox API server port (default 8000).')
  parser.add_option('-l', '--layer', type='int', default=0,
                    help='Layer to target with color commands.')
  parser.add_option('-i', '--interval', type='float', default=0.5,
                    help='Time between each random color fade.')
  options, _arguments = parser.parse_args()
  RandomColorSender(options.host, options.port, options.interval, options.layer)


if __name__ == '__main__':
  main()
