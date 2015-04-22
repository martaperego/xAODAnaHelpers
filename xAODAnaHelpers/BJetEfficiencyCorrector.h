#ifndef xAODAnaHelpers_BJetEfficiencyCorrector_H
#define xAODAnaHelpers_BJetEfficiencyCorrector_H

// EL include(s):
#include <EventLoop/Algorithm.h>

// Infrastructure include(s):
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/TStore.h"

// CP interface includes
#include "PATInterfaces/SystematicRegistry.h"
#include "PATInterfaces/SystematicSet.h"
#include "PATInterfaces/SystematicsUtil.h"
#include "PATInterfaces/SystematicVariation.h"
#include "PATInterfaces/ISystematicsTool.h"

// external tools include(s):
#include "xAODBTaggingEfficiency/BTaggingEfficiencyTool.h"

class BJetEfficiencyCorrector : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:

  xAOD::TEvent *m_event;  //!
  xAOD::TStore *m_store;  //!

  std::string m_name;
  std::string m_configName;

  std::string m_corrFileName;
  std::string m_jetAuthor;
  std::string m_taggerName;
  std::string m_operatingPt;
  bool        m_useDevelopmentFile;
  bool        m_coneFlavourLabel;

  // systematics
  bool m_runAllSyst;                 //!
  std::string m_systName;            //!
  std::string m_outputSystName;      //!
  bool m_runSysts;                    //!
  std::vector<CP::SystematicSet> m_systList; //!

  bool m_debug;                  //!
  bool m_isEMjet;                //!
  bool m_isLCjet;                //!

private:

  // tools
  BTaggingEfficiencyTool  *m_BJetEffSFTool; //!

  // configuration variables
  std::string m_inContainerName;     //!
  std::string m_outContainerName;    //!
  std::string m_outAuxContainerName; //!
  std::string m_decor;            //! The decoration key written to passing objects
  bool  m_btag_veryloose;            //!
  bool  m_btag_loose;                //!
  bool  m_btag_medium;               //!
  bool  m_btag_tight;                //!


  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!


  // this is a standard constructor
  BJetEfficiencyCorrector ();
  BJetEfficiencyCorrector (std::string name, std::string configName);

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // these are the functions not inherited from Algorithm
  virtual EL::StatusCode configure ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(BJetEfficiencyCorrector, 1);
  
};

#endif
